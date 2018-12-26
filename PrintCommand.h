//
// Created by sharon on 21/12/18.
//

#ifndef UNTITLED_PRINTCOMMAND_H
#define UNTITLED_PRINTCOMMAND_H

#include "Command.h"
#include "CalculateExpression.h"
#include "SymbolTable.h"
#include <string>
#include "MakeItDouble.h"

class PrintCommand : public Command {
    SymbolTable *myTable;
    string printVar;
    MakeItDouble myMakeItDouble;
    Expression *pTemp;
public:
    PrintCommand();
    int doCommand(vector<string>);
    void setSymbolTable(SymbolTable *);
    bool checkIfString(string);

    ~PrintCommand();
};


#endif //UNTITLED_PRINTCOMMAND_H
