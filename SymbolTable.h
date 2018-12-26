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
#include "Server.h"
using namespace std;

struct myParams {
    double value;
    string path = "";
};

class SymbolTable {
    unordered_map<string, struct myParams> valueMap;
    Server *myServer;
    Expression *e;
public:
    Expression* getValue(string);
    void setValue(string, double, string);
    string getPath(string s);
    void updateValueAndPath(string, double, string);

    void setServer(Server *);

    ~SymbolTable();
};

#endif //UNTITLED_SYMBOLTABLE_H
