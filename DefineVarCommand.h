//
// Created by hadar on 12/19/18.
//

#ifndef UNTITLED_VARCOMMAND_H
#define UNTITLED_VARCOMMAND_H

#include "Command.h"
#include "CalculateExpression.h"
#include "SymbolTable.h"

class DefineVarCommand : public Command {
    int parametersNum = 3;
    string var;
    double value;
public:
    int doCommand(vector<string>);
};


#endif //UNTITLED_VARCOMMAND_H
