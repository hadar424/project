//
// Created by hadar on 12/19/18.
//

#include "ConditionParser.h"

ConditionParser::ConditionParser() {
    conditionParameters = 3;
}

void ConditionParser::setSymbolTable(SymbolTable* s) {
    myTable =s;
}

void ConditionParser::setCommandMap(unordered_map<string,CommandExpression*> map) {
    commandMap = map;
}

int ConditionParser::doCommand(vector<string> array) {
    MakeItDouble *makeItDouble = new MakeItDouble(myTable);
    vector<string>::iterator it = array.begin();
    //left = setCondition(*it);
    left = makeItDouble->calculateValue(*it);
    it++;
    boolOperator = *it;
    it++;
    right = makeItDouble->calculateValue(*it);
    //right = setCondition(*it);
    it++;
    array.erase(array.begin(),it);
    int result = checkCondition(boolOperator);
    return result;
}

double ConditionParser::setCondition(string s) {
    CalculateExpression* exp;
    try {
        return exp->evaluatePostfix(s)->calculate();
    } catch (exception e) {
        if (myTable->getValue(s) != nullptr) {
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

int ConditionParser::doAllCommands(vector<string> array) {
    vector<string>::iterator iter = array.begin();
    iter += 3;
    array.erase(array.begin(), iter);
    int counter =0;
    int varsInCommend =0;
    vector<string>::iterator it;
    while (*(it = array.begin()) != "}") {
        if((commandMap.find(*it))!= commandMap.end()) {
            CommandExpression* temp = commandMap.find(*it)->second;
            array.erase(array.begin());
            temp->setCommandArray(array);
            varsInCommend = temp->calculate();
            it+= varsInCommend;
            counter+=varsInCommend;
            array.erase(array.begin(), it);
        } else if(myTable->getValue(*it) != NULL) {
            CommandExpression *temp = commandMap.find("=")->second;
            temp->setCommandArray(array);
            varsInCommend = temp->calculate();
            it+= varsInCommend;
            counter+=varsInCommend;
            array.erase(array.begin(), it);
        } else {
            counter++;
            array.erase(array.begin(), it + 1);
        }
    }
    return counter + conditionParameters;
}