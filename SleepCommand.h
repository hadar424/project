//
// Created by sharon on 21/12/18.
//

#ifndef UNTITLED_SLEEPCOMMAND_H
#define UNTITLED_SLEEPCOMMAND_H

#include "Command.h"
#include "CalculateExpression.h"
#include "SymbolTable.h"
#include <string>
#include <unistd.h>


class SleepCommand : public Command {
    SymbolTable *myTable;
    double numOfMilliS;
public:
    int doCommand(vector<string>);

    void setSymbolTable(SymbolTable *);

    double calculateValue(string);

    Expression *IsVar(string);
};


#endif //UNTITLED_SLEEPCOMMAND_H