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
    AssignCommand* assignC = new AssignCommand();
    DefineVarCommand* defineC = new DefineVarCommand();
    PrintCommand* printC = new PrintCommand();
    SleepCommand* sleepC = new SleepCommand();
    ConnectCommand* connectC = new ConnectCommand();
    LoopCondition* loopC = new LoopCondition();
    IfCondition* ifConditionC = new IfCondition();
    OpenServerCommand* serverC = new OpenServerCommand();
    CommandExpression *server = new CommandExpression(serverC);
    CommandExpression *connect = new CommandExpression(connectC);
    CommandExpression *define = new CommandExpression(defineC);
    CommandExpression *loop = new CommandExpression(loopC);
    CommandExpression *ifCondition = new CommandExpression(ifConditionC);
    CommandExpression *print = new CommandExpression(printC);
    CommandExpression *sleep = new CommandExpression(sleepC);
    CommandExpression *assign = new CommandExpression(assignC);
    SymbolTable* myTable;
    unordered_map<string,CommandExpression*> commandMap;
public:
    Data(SymbolTable*);

    unordered_map<string,CommandExpression*> getMap();

    ~Data();
};


#endif //UNTITLED_DATA_H
