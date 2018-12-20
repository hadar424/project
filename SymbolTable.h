//
// Created by hadar on 12/19/18.
//

#ifndef UNTITLED_SYMBOLTABLE_H
#define UNTITLED_SYMBOLTABLE_H
#include <string>
#include <unordered_map>
#include <iostream>
#include <map>
#include "Number.h"

using namespace std;

class SymbolTable {
    unordered_map<string,double> valueMap;
    unordered_map<string,double>::iterator valueIt;
public:
    SymbolTable() = default;
    Expression* getValue(string);
    void setValue(string,double);
};


#endif //UNTITLED_SYMBOLTABLE_H
