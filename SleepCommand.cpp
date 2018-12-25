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
                myMakeItDouble = new MakeItDouble(myTable);
                numOfSeconds = myMakeItDouble->calculateValue(*it);
            } catch (exception e) {
                throw invalid_argument("invalid define");
            }
        }
    }

    sleep(numOfSeconds / 1000);
    cout << "done Sleep" << endl;
    return parametersNum + 1;
}