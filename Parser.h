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
#include "AssignCommand.h"

using namespace std;

class MyParser {
    vector<string> commandArray;
    unordered_map<string,Command*> commandMap;
    SymbolTable* myTable = new SymbolTable;
    OpenServerCommand *server = new OpenServerCommand();
    ConnectCommand *connect = new ConnectCommand();
    DefineVarCommand *define = new DefineVarCommand();
    ConditionParser *condition = new ConditionParser();
    LoopCondition *loop = new LoopCondition(condition);
    IfCondition *ifCondition = new IfCondition(condition);
    PrintCommand *printV = new PrintCommand();
    SleepCommand *sleepV = new SleepCommand();
    AssignCommand *assignC = new AssignCommand();
public:
    MyParser(vector<string>);
    void parser();

    ~MyParser();
};


#endif //PROJECT_PARSER_H
