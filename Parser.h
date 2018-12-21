#ifndef PROJECT_PARSER_H
#define PROJECT_PARSER_H

#include <string>
#include <iostream>
#include "ConnectCommand.h"
#include "OpenServerCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include <vector>
#include "DefineVarCommand.h"
#include "LoopCondition.h"
#include "IfCondition.h"

using namespace std;

class MyParser {
    vector<string> commandArray;
    unordered_map<string,Command*> commandMap;
    SymbolTable* myTable = new SymbolTable;
public:
    MyParser(vector<string>);
    void parser();
};


#endif //PROJECT_PARSER_H
