//
// Created by sharon on 22/12/18.
//

#include "MakeItDouble.h"

MakeItDouble::MakeItDouble(SymbolTable *map) {
    myTable = map;
}

double MakeItDouble::getValue() {
    return value;
}

bool MakeItDouble::IsOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
        return true;
    }
    return false;
}

double MakeItDouble::calculateValue(string myString) {
    var = myString;
    value = 0;
    int lastOperator = -1;
    CalculateExpression exp;
    string copy = var;
    for (int i = 0; i < (var = copy).length(); i++) {
        if (IsOperator(copy[i])) {
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

    Expression *pExp = nullptr;
    try {
        pExp = exp.evaluatePostfix(var);
    }
    catch (exception e) {
        throw invalid_argument("invalid expression string");
    }
    try {
        value = pExp->calculate();
        return value;
    }
    catch (exception e) {
        throw invalid_argument("invalid expression string");
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