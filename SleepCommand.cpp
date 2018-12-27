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
    Expression *e = nullptr;
    try {
        // try to calculate
        string tempStr = *it;
        e = exp.evaluatePostfix(tempStr);
        numOfSeconds = e->calculate();
        if (e != nullptr) {
            delete e;
        }
    } catch (exception &e1) {
        string tempStr = *it;
        // check if the parameter is var (on table)
        e = myTable->getValue(tempStr);
        if (e != nullptr) {
            numOfSeconds = e->calculate();
            delete e;
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