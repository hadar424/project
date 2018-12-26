//
// Created by sharon on 22/12/18.
//

#include "AssignCommand.h"

AssignCommand::AssignCommand() {
    parametersNum = 1;
}

void AssignCommand::setSymbolTable(SymbolTable *map) {
    myTable = map;
}

void AssignCommand::setServer(Server *server) {
    myServer = server;
}

void AssignCommand::setClient(Client *client) {
    myClient = client;
}

int AssignCommand::doCommand(vector<string> array) {
    parametersNum = 1;
    vector<string>::iterator it = array.begin();
    path = "";
    var = *it;
    value = 0;
    string serverPath;
    bool needChangeClient = false;
    if (myTable->getValue(var) != nullptr) {
        if (myTable->getPath(var).compare("") != 0) {
            path = myTable->getPath(var);
            value = myTable->getValue(var)->calculate();
            needChangeClient = true;
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
            string newPath = cleanPath(*it);
            path = newPath;
            if (myServer->getValueFromMap(newPath) != nullptr) {
                value = myServer->getValueFromMap(newPath)->calculate();
            } else {
                value = 0;
            }
        }
    } else {
        try {
            value = exp->evaluatePostfix(*it)->calculate();
        } catch (exception &e) {
            if (myTable->getValue(*it) != nullptr) {
                value = myTable->getValue(*it)->calculate();
            } else {
                myMakeItDouble = new MakeItDouble(myTable);
                value = myMakeItDouble->calculateValue(*it);
            }
        }
    }
    cout << "assigned value to var " + var + "=" + to_string(value) << endl;
    myTable->setValue(var, value, path);
    if (needChangeClient) {
        cout << "updating the simulator " + serverPath + "=" + to_string(value) << endl;
        myClient->setValueInMap(path, value);
    }

    if (isBind) {
        parametersNum++;
    }
    return parametersNum + 1;
}

string AssignCommand::cleanPath(string s) {
    s.erase(0, 1);
    s.erase(s.length() - 1, s.length());
    return s;
}