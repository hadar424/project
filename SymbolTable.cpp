//
// Created by hadar on 12/19/18.
//

#include "SymbolTable.h"

Expression* SymbolTable::getValue(string s) {
    Expression *exp = nullptr;
    if((valueMap.find(s)) != valueMap.end()) {
        e = myServer->getValueFromMap(valueMap.find(s)->second.path);
        if (myServer->getValueFromMap(valueMap.find(s)->second.path) != nullptr) {
            exp = e;
        } else {
            exp = new Number(valueMap.find(s)->second.value);
        }
    }
    return exp;
}

void SymbolTable::setServer(Server *server) {
    myServer = server;
}

string SymbolTable::getPath(string s) {
    string path = "";
    if ((valueMap.find(s)) != valueMap.end()) {
        path = valueMap.find(s)->second.path;
    }
    return path;
}

void SymbolTable::setValue(string s, double num, string path) {
    if (getValue(s) == nullptr) {
        struct myParams *params = new myParams();
        params->value = num;
        params->path = path;
        valueMap.insert(make_pair(s, *params));
    } else {
        updateValueAndPath(s, num, path);
    }

}

void SymbolTable::updateValueAndPath(string s, double num, string path) {
    valueMap.find(s)->second.value = num;
    valueMap.find(s)->second.path = path;
}

SymbolTable::~SymbolTable() {
    delete e;
}
