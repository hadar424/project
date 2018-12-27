#ifndef UNTITLED_VARCOMMAND_H
#define UNTITLED_VARCOMMAND_H

#include "Command.h"
#include "SymbolTable.h"
#include <string>


class DefineVarCommand : public Command {
    int parametersNum;
    string var;
    SymbolTable* myTable;

public:
    DefineVarCommand();
    int doCommand(vector<string>);
    void setSymbolTable(SymbolTable *);
};


#endif //UNTITLED_VARCOMMAND_H
