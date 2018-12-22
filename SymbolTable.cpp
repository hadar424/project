//
// Created by hadar on 12/19/18.
//

#include "SymbolTable.h"

Expression* SymbolTable::getValue(string s) {
    if((valueMap.find(s)) != valueMap.end()) {
        Expression *exp = new Number(valueMap.find(s)->second.value);
        return exp;
    } else {
        return nullptr;
    }
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

