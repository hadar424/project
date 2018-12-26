//
// Created by hadar on 12/23/18.
//

#ifndef UNTITLED_DATA_H
#define UNTITLED_DATA_H

#include "CommandExpression.h"
#include "ConnectCommand.h"
#include "OpenServerCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "DefineVarCommand.h"
#include "LoopCondition.h"
#include "IfCondition.h"
#include "AssignCommand.h"
#include "ConditionParser.h"

class Data {
    AssignCommand *assignC;
    DefineVarCommand *defineC;
    PrintCommand *printC;
    SleepCommand *sleepC;
    ConnectCommand *connectC;
    LoopCondition *loopC;
    IfCondition *ifConditionC;
    OpenServerCommand *serverC;
    CommandExpression *server;
    CommandExpression *connect;
    CommandExpression *define;
    CommandExpression *loop;
    CommandExpression *ifCondition;
    CommandExpression *print;
    CommandExpression *sleep;
    CommandExpression *assign;
    SymbolTable* myTable;
    unordered_map<string,CommandExpression*> commandMap;
public:
    Data(SymbolTable*);

    unordered_map<string,CommandExpression*> getMap();

    ~Data();
};


#endif //UNTITLED_DATA_H
