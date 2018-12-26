//
// Created by sharon on 21/12/18.
//

#include "PrintCommand.h"

PrintCommand::PrintCommand() {
    printVar = "";
}

void PrintCommand::setSymbolTable(SymbolTable *map) {
    myTable = map;
}

int PrintCommand::doCommand(vector<string> array) {
    int counter = 0;
    double value;
    printVar = "";
    vector<string>::iterator it;
    CalculateExpression *exp;
    for (it = array.begin(); (*it).compare("\\n") != 0; it++) {
        try {
            value = exp->evaluatePostfix(*it)->calculate();
            printVar += to_string(value) + " ";
            counter++;
        } catch (exception &e) {
            if (myTable->getValue(*it) != nullptr) {
                value = myTable->getValue(*it)->calculate();
                printVar += to_string(value)+" ";
                counter++;
            } else {
                try {
                    myMakeItDouble = new MakeItDouble(myTable);
                    value = myMakeItDouble->calculateValue(*it);
                    printVar += to_string(value)+" ";
                    counter++;
                } catch (exception &e) {
                    if (checkIfString(*it)) {
                        printVar += (*it).substr(1, (*it).length() - 2) +" ";
                        counter++;
                    } else {
                        throw invalid_argument("invalid argument");
                    }
                }
            }
        }
    }
    cout << printVar << endl;
    return counter + 1;
}


bool PrintCommand::checkIfString(string s) {
    if (s[0] != '"' || s[s.length() - 1] != '"')
        return false;
    return true;
}