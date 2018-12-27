#include "AssignCommand.h"

/*
 * Function Name:
 * Input:
 * Output:
 * Function Operation:
 */
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
    e1 = myTable->getValue(var);
    if (e1 != nullptr) {
        if (myTable->getPath(var).compare("") != 0) {
            path = myTable->getPath(var);
            value = e1->calculate();
            needChangeClient = true;
        }
    }

    it += 2;
    bool isBind = false;
    CalculateExpression exp;
    if ((*it).compare("bind") == 0) {
        isBind = true;
        it++;
        e1 = myTable->getValue(*it);
        if (e1 != nullptr) {
            path = myTable->getPath(*it);
            value = e1->calculate();
        } else {
            string newPath = cleanPath(*it);
            path = newPath;
            e1 = myServer->getValueFromMap(newPath);
            if (e1 != nullptr) {
                value = e1->calculate();
            } else {
                value = 0;
            }
        }
    } else {
        try {
            e = exp.evaluatePostfix(*it);
            value = e->calculate();
        } catch (exception &e) {
            e1 = myTable->getValue(*it);
            if (e1 != nullptr) {
                value = e1->calculate();
            } else {
                value = myMakeItDouble.calculateValue(*it, myTable);
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

AssignCommand::~AssignCommand() {
    delete e;
    delete e1;
}