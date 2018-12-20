//
// Created by hadar on 12/19/18.
//

#ifndef UNTITLED_CONDITIONPARSER_H
#define UNTITLED_CONDITIONPARSER_H

#include "Command.h"
#include "CalculateExpression.h"
#include "SymbolTable.h"

class ConditionParser : public Command {
    double left;
    double right;
    string boolOperator;
public:
    ConditionParser() = default;
    int doCommand(vector<string>);
    double setCondition(string s);
    int checkCondition(string s);
};


#endif //UNTITLED_CONDITIONPARSER_H
