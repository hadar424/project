//
// Created by hadar on 12/19/18.
//

#ifndef UNTITLED_VARCOMMAND_H
#define UNTITLED_VARCOMMAND_H

#include "Command.h"
#include "CalculateExpression.h"
#include "SymbolTable.h"
#include <string>
#include "MakeItDouble.h"

class DefineVarCommand : public Command {
    int parametersNum = 3;
    string var;
    double value;
    SymbolTable* myTable;
    MakeItDouble *myMakeItDouble;
public:
    DefineVarCommand() = default;
    int doCommand(vector<string>);

    void setSymbolTable(SymbolTable *);
};


#endif //UNTITLED_VARCOMMAND_H
