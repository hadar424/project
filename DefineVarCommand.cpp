//
// Created by hadar on 12/19/18.
//

#include "DefineVarCommand.h"

int DefineVarCommand::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    var = *it;
    it++;
    if (*it != "=") {
        throw invalid_argument("invalid define");
    }
    it++;
    CalculateExpression* exp;
    try {
        value = exp->evaluatePostfix(*it)->calculate();
    } catch (exception e){
        if(myTable->getValue(*it) != NULL) {
            value = myTable->getValue(*it)->calculate();
        } else {
            throw invalid_argument("invalid define");
        }
    }
    myTable->setValue(var,value);
    return parametersNum +1;
}