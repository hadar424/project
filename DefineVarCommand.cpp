#include "DefineVarCommand.h"

/*
 * Function Name: DefineVarCommand
 * Input: -
 * Output: -
 * Function Operation: constructor, initialize the members
 */
DefineVarCommand::DefineVarCommand() {
    parametersNum = 0;
    var = "";
}

/*
 * Function Name: setSymbolTable
 * Input: SymbolTable* map
 * Output: -
 * Function Operation: set symbol table
 */
void DefineVarCommand::setSymbolTable(SymbolTable *map) {
    myTable = map;
}

/*
 * Function Name: doCommand
 * Input: vector<string> array
 * Output: -
 * Function Operation: set the map, add the var (empty value and path)
 */
int DefineVarCommand::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    var = *it;
    myTable->setValue(var, 0, "");
    return parametersNum;
}


