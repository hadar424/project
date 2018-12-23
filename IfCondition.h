//
// Created by hadar on 12/21/18.
//

#ifndef UNTITLED_IFCONDITION_H
#define UNTITLED_IFCONDITION_H

#include "ConditionParser.h"
#include "CommandExpression.h"

class IfCondition : public ConditionParser{
    int parametersNum = 1;
public:
    int doCommand(vector<string>);

};

#endif //UNTITLED_IFCONDITION_H
