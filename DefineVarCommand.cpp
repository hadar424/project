//
// Created by hadar on 12/19/18.
//

#include "DefineVarCommand.h"

int DefineVarCommand::doCommand(vector<string> array) {
    SymbolTable* table;
    vector<string>::iterator it = array.begin();
    var = *it;
    it++;
    if (*it != "=") {
        throw invalid_argument("invalid define");
    }
    it++;
    CalculateExpression* exp;
    if(exp->evaluatePostfix(*it) != NULL) {
        value = exp->evaluatePostfix(*it)->calculate();
    } else if(table->getValue(*it) != NULL) {
        value = table->getValue(*it)->calculate();
    } else {
        throw invalid_argument("invalid define");
    }
    table->setValue(var,value);
    return parametersNum;
}