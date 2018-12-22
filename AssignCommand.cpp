//
// Created by sharon on 22/12/18.
//

#include "AssignCommand.h"

void AssignCommand::setSymbolTable(SymbolTable *map) {
    myTable = map;
}

void AssignCommand::setServer(Server *server) {
    myServer = server;
}

int AssignCommand::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    var = *it;
    string serverPath;
    bool needChangeServer = false;
    if (myTable->getValue(var) != nullptr) {
        if (myTable->getPath(var).compare("") != 0) {
            serverPath = myTable->getPath(var);
            if (myServer->getValueFromMap(*it) != nullptr) {
                needChangeServer = true;
            }
        }
    }

    it += 2;
    bool isBind = false;
    CalculateExpression *exp;
    if ((*it).compare("bind") == 0) {
        isBind = true;
        it++;
        if (myTable->getValue(*it) != nullptr) {
            path = myTable->getPath(*it);
            value = myTable->getValue(*it)->calculate();
        } else {
            if (myServer->getValueFromMap(*it) != nullptr) {
                path = *it;
                value = myServer->getValueFromMap(*it)->calculate();
            } else {
                throw invalid_argument("invalid path");
            }
        }
    } else {
        path = "";
        try {
            value = exp->evaluatePostfix(*it)->calculate();
        } catch (exception &e) {
            if (myTable->getValue(*it) != nullptr) {
                value = myTable->getValue(*it)->calculate();
            } else {
                myMakeItDouble = new MakeItDouble(*it, myTable);
                value = myMakeItDouble->calculateValue();
            }
        }
    }
    myTable->setValue(var, value, path);
    if (needChangeServer) {
        myServer->setValueInMap(serverPath, value);
    }

    if (isBind) {
        parametersNum++;
    }
    return parametersNum + 1;
}