//
// Created by hadar on 12/19/18.
//

#include "DefineVarCommand.h"

void DefineVarCommand::setSymbolTable(SymbolTable *map) {
    myTable = map;
}

int DefineVarCommand::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    var = *it;
    myTable->setValue(var, 0, "");
    return parametersNum;
}

