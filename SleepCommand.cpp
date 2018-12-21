//
// Created by sharon on 21/12/18.
//

#include "SleepCommand.h"

void SleepCommand::setSymbolTable(SymbolTable *map) {
    myTable = map;
}

int SleepCommand::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    CalculateExpression *exp;
    try {
        numOfMilliS = exp->evaluatePostfix(*it)->calculate();
    } catch (exception e) {
        if (myTable->getValue(*it) != NULL) {
            numOfMilliS = myTable->getValue(*it)->calculate();
        } else {
            try {
                numOfMilliS = calculateValue(*it);
            } catch (exception e) {
                throw invalid_argument("invalid define");
            }
        }
    }

    sleep(numOfMilliS);
    cout << "done sleep" << endl;
    return 1;
}

double SleepCommand::calculateValue(string s) {
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

Expression *SleepCommand::IsVar(string s) {
    Expression *newExp;
    if ((newExp = myTable->getValue(s)) != NULL) {
        return newExp;
    } else {
        return NULL;
    }
}