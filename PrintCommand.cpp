#include "PrintCommand.h"

/*
 * Function Name: PrintCommand
 * Input: -
 * Output: -
 * Function Operation: constructor, initialize member
 */
PrintCommand::PrintCommand() {
    printVar = "";
}

/*
 * Function Name: setSymbolTable
 * Input: SymbolTable* map
 * Output: -
 * Function Operation: set symbol table
 */
void PrintCommand::setSymbolTable(SymbolTable *map) {
    myTable = map;
}

/*
 * Function Name: doCommand
 * Input: vector<string> array
 * Output: -
 * Function Operation: print the parameters
 */
int PrintCommand::doCommand(vector<string> array) {
    int counter = 0;
    double value;
    printVar = "";
    vector<string>::iterator it;
    CalculateExpression exp;
    // loop over all the parameters
    for (it = array.begin(); (*it).compare("\\n") != 0; it++) {
        try {
            // try to calculate
            string temp = *it;
            pTemp = exp.evaluatePostfix(temp);
            value = pTemp->calculate();
            printVar += to_string(value) + " ";
            counter++;
        } catch (exception &e) {
            // check if the parameter is var (on table)
            if ((pTemp = myTable->getValue(*it)) != nullptr) {
                value = pTemp->calculate();
                printVar += to_string(value) + " ";
                counter++;
            } else {
                try {
                    // check if mix of var and numbers
                    value = myMakeItDouble.calculateValue(*it, myTable);
                    printVar += to_string(value) + " ";
                    counter++;
                } catch (exception &e) {
                    // check if valid string
                    if (checkIfString(*it)) {
                        printVar += (*it).substr(1, (*it).length() - 2) + " ";
                        counter++;
                    } else {
                        throw invalid_argument("invalid argument");
                    }
                }
            }
        }
    }
    // print all the parameters
    cout << printVar << endl;
    return counter + 1;
}

/*
 * Function Name: checkIfString
 * Input: string s
 * Output: bool (true/false)
 * Function Operation: check if string (format: "string")
 */
bool PrintCommand::checkIfString(string s) {
    if (s[0] != '"' || s[s.length() - 1] != '"')
        return false;
    return true;
}

/*
 * Function Name: ~PrintCommand
 * Input: -
 * Output: -
 * Function Operation: destructor
 */
PrintCommand::~PrintCommand() {
    delete pTemp;
}