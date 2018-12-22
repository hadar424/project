//
// Created by sharon on 22/12/18.
//

#ifndef UNTITLED_ASSIGNCOMMAND_H
#define UNTITLED_ASSIGNCOMMAND_H

#include "Command.h"
#include "SymbolTable.h"
#include "Server.h"
#include "MakeItDouble.h"
#include "CalculateExpression.h"
#include <string>

class AssignCommand : public Command {
    Server *myServer;
    SymbolTable *myTable;
    string var;
    double value;
    string path;
    int parametersNum = 1;
    MakeItDouble *myMakeItDouble;
public:
    int doCommand(vector<string>);

    void setSymbolTable(SymbolTable *);

    void setServer(Server *);
};


#endif //UNTITLED_ASSIGNCOMMAND_H
