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
    AssignCommand *assignC = nullptr;
    DefineVarCommand *defineC = nullptr;
    PrintCommand *printC = nullptr;
    SleepCommand *sleepC = nullptr;
    ConnectCommand *connectC = nullptr;
    LoopCondition *loopC = nullptr;
    IfCondition *ifConditionC = nullptr;
    OpenServerCommand *serverC = nullptr;
    CommandExpression *server = nullptr;
    CommandExpression *connect = nullptr;
    CommandExpression *define = nullptr;
    CommandExpression *loop = nullptr;
    CommandExpression *ifCondition = nullptr;
    CommandExpression *print = nullptr;
    CommandExpression *sleep = nullptr;
    CommandExpression *assign = nullptr;
    SymbolTable *myTable = nullptr;
    unordered_map<string, CommandExpression *> commandMap = {};
public:
    Data(SymbolTable*);
    unordered_map<string,CommandExpression*> getMap();
    ~Data();
};


#endif //UNTITLED_DATA_H