//
// Created by hadar on 12/19/18.
//

#include "DefineVarCommand.h"

void DefineVarCommand::setSymbolTable(SymbolTable* map) {
    myTable = map;
}

int DefineVarCommand::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    var = *it;
    it++;
    if (*it != "=") {
        throw invalid_argument("invalid define");
    }
    it++;
    CalculateExpression* exp;
    try {
        value = exp->evaluatePostfix(*it)->calculate();
    } catch (exception e){
        if(myTable->getValue(*it) != NULL) {
            value = myTable->getValue(*it)->calculate();
        } else {
            value = calculateValue(*it);
        }
    }
    if(myTable->getValue(var) != NULL) {
        myTable->updateValue(var,value);
    } else {
        myTable->setValue(var,value);
    }
    return parametersNum +1;
}

double DefineVarCommand::calculateValue(string s) {
    int lastOperator = -1;
    CalculateExpression* exp;
    string copy = s;
    for(int i=0; i<(s =copy).length(); i++) {
        if(exp->IsOperator(copy[i])) {
            string left = copy.substr(lastOperator+1,i-lastOperator-1);
            int length = left.length();
            if(IsVar(left)) {
                string temp = to_string(myTable->getValue(left)->calculate());
                copy.erase(lastOperator + 1,left.length());
                copy = copy.substr(0,lastOperator+1) + temp + copy.substr(lastOperator +1);
                length = temp.length();
            }
            lastOperator = lastOperator+length +1;
            i=lastOperator;
        }
        if(i == copy.length()-1) {
            string left = copy.substr(lastOperator+1);
            if(IsVar(left)) {
                string temp = to_string(myTable->getValue(left)->calculate());
                copy.erase(lastOperator + 1);
                copy = copy.substr(0, lastOperator + 1) + temp;
            }
        }
    }
    try {
        return exp->evaluatePostfix(s)->calculate();
    } catch (exception e) {
        throw invalid_argument("invalid define");
    }
}

Expression* DefineVarCommand::IsExpression(string s) {
    CalculateExpression* exp;
    try {
        Expression* newExp = exp->evaluatePostfix(s);
        return newExp;
    } catch (exception e) {
        return NULL;
    }
}

Expression* DefineVarCommand::IsVar(string s) {
    Expression* newExp;
    if((newExp = myTable->getValue(s)) != NULL) {
        return newExp;
    } else {
        return NULL;
    }
}