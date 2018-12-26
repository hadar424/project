//
// Created by sharon on 22/12/18.
//

#include "MakeItDouble.h"

MakeItDouble::MakeItDouble() {
    value = 0;
    var = "";
}

bool MakeItDouble::IsOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
        return true;
    }
    return false;
}

double MakeItDouble::calculateValue(string myString, SymbolTable *map) {
    var = myString;
    value = 0;
    myTable = map;
    int lastOperator = -1;
    CalculateExpression exp;
    string copy = var;
    for (unsigned int i = 0; i < (var = copy).length(); i++) {
        if (IsOperator(copy[i])) {
            string left = copy.substr(lastOperator + 1, i - lastOperator - 1);
            int length = left.length();
            if (IsVar(left)) {
                e = myTable->getValue(left);
                string temp = to_string(e->calculate());
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
                e = myTable->getValue(left);
                string temp = to_string(e->calculate());
                copy.erase(lastOperator + 1);
                copy = copy.substr(0, lastOperator + 1) + temp;
            }
        }
    }
    try {
        e = exp.evaluatePostfix(var);
        value = e->calculate();
        return value;
    }
    catch (exception &e1) {
        throw invalid_argument("invalid expression string");
    }
}

Expression *MakeItDouble::IsVar(string s) {
    e = myTable->getValue(s);
    return e;
}

MakeItDouble::~MakeItDouble() {
    delete e;
}