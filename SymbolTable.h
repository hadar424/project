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

struct myParams {
    double value;
    string path;
};

class SymbolTable {
    unordered_map<string, struct myParams> valueMap;
    unordered_map<string, struct myParams>::iterator valueIt;
public:
    SymbolTable() = default;
    Expression* getValue(string);

    void setValue(string, double, string);

    void updateValueAndPath(string, double, string);
};


#endif //UNTITLED_SYMBOLTABLE_H
