//
// Created by sharon on 21/12/18.
//

#ifndef UNTITLED_PRINTCOMMAND_H
#define UNTITLED_PRINTCOMMAND_H

#include "Command.h"
#include "CalculateExpression.h"
#include "SymbolTable.h"
#include <string>

class PrintCommand : public Command {
    SymbolTable *myTable;
    string printVar = "";
public:
    int doCommand(vector<string>);
    void setSymbolTable(SymbolTable *);
    bool checkIfString(string);
    double calculateValue(string);
    Expression *IsVar(string);
};


#endif //UNTITLED_PRINTCOMMAND_H
