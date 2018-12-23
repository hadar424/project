//
// Created by hadar on 12/19/18.
//

#include "ConditionParser.h"

void ConditionParser::setSymbolTable(SymbolTable* s) {
    myTable =s;
}

void ConditionParser::setCommandMap(unordered_map<string,CommandExpression*> map) {
    commandMap = map;
}


int ConditionParser::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    left = setCondition(*it);
    it++;
    boolOperator = *it;
    it++;
    right = setCondition(*it);
    it++;
    array.erase(array.begin(),it);
    commands = array;
    int result = checkCondition(boolOperator);
    return result;
}

double ConditionParser::setCondition(string s) {
    CalculateExpression* exp;
    try {
        return exp->evaluatePostfix(s)->calculate();
    } catch (exception e) {
        if(myTable->getValue(s) != NULL) {
            return myTable->getValue(s)->calculate();
        }
        throw invalid_argument("invalid condition");
    }
}

int ConditionParser::checkCondition(string s) {
    if(s.compare(">=") == 0) {
        if(left >= right) {
            return 1;
        }
    } else if(s.compare("<=") == 0) {
        if(left <= right) {
            return 1;
        }
    } else if(s.compare("==") == 0) {
        if(left == right) {
            return 1;
        }
    } else if(s.compare("<") == 0) {
        if(left < right) {
            return 1;
        }
    } else if(s.compare(">") == 0) {
        if (left > right) {
            return 1;
        }
    } else if(s.compare("!=") == 0) {
        if(left != right) {
            return 1;
        }
    } else {
        throw invalid_argument("invalid condition");
    }
    return 0;
}

int ConditionParser::doAllCommands() {
    int counter =0;
    int varsInCommend =0;
    vector<string>::iterator it;
    while(*(it = commands.begin()) != "}") {
        if((commandMap.find(*it))!= commandMap.end()) {
            CommandExpression* temp = commandMap.find(*it)->second;
            commands.erase(commands.begin());
            temp->setCommandArray(commands);
            varsInCommend = temp->calculate();
            it+= varsInCommend;
            counter+=varsInCommend;
            commands.erase(commands.begin(),it);
        } else if(myTable->getValue(*it) != NULL) {
            CommandExpression *temp = commandMap.find("var")->second;
            temp->setCommandArray(commands);
            varsInCommend = temp->calculate();
            it+= varsInCommend;
            counter+=varsInCommend;
            commands.erase(commands.begin(),it);
        } else {
            counter++;
            commands.erase(commands.begin(),it+1);
        }
    }
    return counter + conditionParameters;
}