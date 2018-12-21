//
// Created by sharon on 21/12/18.
//

#include "PrintCommand.h"

void PrintCommand::setSymbolTable(SymbolTable *map) {
    myTable = map;
}

int PrintCommand::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    double value;
    CalculateExpression *exp;
    try {
        value = exp->evaluatePostfix(*it)->calculate();
        printVar = to_string(value);
    } catch (exception e) {
        if (myTable->getValue(*it) != NULL) {
            value = myTable->getValue(*it)->calculate();
            printVar = to_string(value);
        } else {
            value = calculateValue(*it);
            printVar = to_string(value);
        }
    }
    if (myTable->getValue(*it) == NULL) {
        if (checkIfString(*it))
            printVar = *it;
    }
    cout << printVar;
    return 1;
}

double PrintCommand::calculateValue(string s) {
    int lastOperator = -1;
    CalculateExpression *exp;
    string copy = s;
    for (int i = 0; i < (s = copy).length(); i++) {
        if (exp->IsOperator(copy[i])) {
            string left = copy.substr(lastOperator + 1, i - lastOperator - 1);
            int length = left.length();
            if (IsVar(left)) {
                string temp = to_string(myTable->getValue(left)->calculate());
                copy.erase(lastOperator + 1, left.length());
                copy = copy.substr(0, lastOperator + 1) + temp + copy.substr(lastOperator + 1);
                length = temp.length();
            }
            lastOperator = lastOperator + length + 1;
            i = lastOperator;
        }
        if (i == copy.length() - 1) {
            string left = copy.substr(lastOperator + 1);
            if (IsVar(left)) {
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

Expression *PrintCommand::IsVar(string s) {
    Expression *newExp;
    if ((newExp = myTable->getValue(s)) != NULL) {
        return newExp;
    } else {
        return NULL;
    }
}

bool PrintCommand::checkIfString(string s) {
    if (s[0] != '"' || s[s.length() - 1] != '"')
        return false;
    return true;
}