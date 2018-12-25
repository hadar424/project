//
// Created by hadar on 12/19/18.
//

#ifndef UNTITLED_CONDITIONPARSER_H
#define UNTITLED_CONDITIONPARSER_H


#include <list>
#include "Command.h"
#include "CalculateExpression.h"
#include "SymbolTable.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "CommandExpression.h"
#include "MakeItDouble.h"


class ConditionParser : public Command {
    double left;
    double right;
    string boolOperator;
    SymbolTable* myTable;
    unordered_map<string,CommandExpression*> commandMap;
    int conditionParameters = 3;

public:
    ConditionParser() = default;
    int doCommand(vector<string>);
    double setCondition(string s);
    int checkCondition(string s);

    int doAllCommands(vector<string>);
    void setSymbolTable(SymbolTable*);
    void setCommandMap(unordered_map<string,CommandExpression*>);

};


#endif //UNTITLED_CONDITIONPARSER_H
