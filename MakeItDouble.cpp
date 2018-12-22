//
// Created by sharon on 22/12/18.
//

#include "MakeItDouble.h"

MakeItDouble::MakeItDouble(string myString, SymbolTable *map) {
    myTable = map;
    var = myString;
}

double MakeItDouble::getValue() {
    return value;
}

double MakeItDouble::calculateValue() {
    int lastOperator = -1;
    CalculateExpression *exp;
    string copy = var;
    for (int i = 0; i < (var = copy).length(); i++) {
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
        return exp->evaluatePostfix(var)->calculate();
    } catch (exception e) {
        throw invalid_argument("invalid define");
    }
}

Expression *MakeItDouble::IsExpression(string s) {
    CalculateExpression *exp;
    try {
        Expression *newExp = exp->evaluatePostfix(s);
        return newExp;
    } catch (exception e) {
        return NULL;
    }
}

Expression *MakeItDouble::IsVar(string s) {
    Expression *newExp;
    if ((newExp = myTable->getValue(s)) != NULL) {
        return newExp;
    } else {
        return NULL;
    }
}