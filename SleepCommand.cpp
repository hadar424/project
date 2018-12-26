//
// Created by sharon on 21/12/18.
//

#include "SleepCommand.h"

SleepCommand::SleepCommand() {
    parametersNum = 1;
}

void SleepCommand::setSymbolTable(SymbolTable *map) {
    myTable = map;
}

int SleepCommand::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    CalculateExpression exp;
    try {
        e = exp.evaluatePostfix(*it);
        numOfSeconds = e->calculate();
    } catch (exception &e1) {
        if ((e = myTable->getValue(*it)) != nullptr) {
            numOfSeconds = e->calculate();
        } else {
            try {
                numOfSeconds = myMakeItDouble.calculateValue(*it, myTable);
            } catch (exception &e) {
                throw invalid_argument("invalid define");
            }
        }
    }


    cout << "going to sleep for " << numOfSeconds << " mili seconds" << endl;
    usleep(numOfSeconds * 1000);
    cout << "done Sleep" << endl;
    return parametersNum + 1;
}

SleepCommand::~SleepCommand() {
    delete e;
}