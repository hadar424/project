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
        numOfSeconds = exp->evaluatePostfix(*it)->calculate();
    } catch (exception e) {
        if (myTable->getValue(*it) != NULL) {
            numOfSeconds = myTable->getValue(*it)->calculate();
        } else {
            try {
                myMakeItDouble = new MakeItDouble(*it, myTable);
                numOfSeconds = myMakeItDouble->calculateValue();
            } catch (exception e) {
                throw invalid_argument("invalid define");
            }
        }
    }

    sleep(numOfSeconds);
    cout << "done Sleep" << endl;
    return parametersNum + 1;
}