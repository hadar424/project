//
// Created by sharon on 21/12/18.
//

#include "SleepCommand.h"

/*
 * Function Name: SleepCommand
 * Input: -
 * Output: -
 * Function Operation: constructor, initialize member
 */
SleepCommand::SleepCommand() {
    parametersNum = 1;
}

/*
 * Function Name: setSymbolTable
 * Input: SymbolTable* map
 * Output: -
 * Function Operation: set symbol table
 */
void SleepCommand::setSymbolTable(SymbolTable *map) {
    myTable = map;
}

/*
 * Function Name: doCommand
 * Input: vector<string> array
 * Output: -
 * Function Operation: sleep according to param
 */
int SleepCommand::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    CalculateExpression exp;
    try {
        // try to calculate
        e = exp.evaluatePostfix(*it);
        numOfSeconds = e->calculate();
    } catch (exception &e1) {
        // check if the parameter is var (on table)
        if ((e = myTable->getValue(*it)) != nullptr) {
            numOfSeconds = e->calculate();
        } else {
            try {
                // check if mix of var and numbers
                numOfSeconds = myMakeItDouble.calculateValue(*it, myTable);
            } catch (exception &e) {
                throw invalid_argument("invalid define");
            }
        }
    }
    // sleep this time
    usleep(numOfSeconds * 1000);
    return parametersNum + 1;
}

/*
 * Function Name: ~SleepCommand
 * Input: -
 * Output: -
 * Function Operation: destructor
 */
SleepCommand::~SleepCommand() {
    delete e;
}