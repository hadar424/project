//
// Created by hadar on 12/23/18.
//

#ifndef UNTITLED_COMMANDEXPRESSION_H
#define UNTITLED_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"

class CommandExpression : public Expression {
    Command* myCommand;
    vector<string> myCommandArray;
public:
    CommandExpression(Command* c);
    double calculate();
    void setCommandArray(vector<string>);
};


#endif //UNTITLED_COMMANDEXPRESSION_H
