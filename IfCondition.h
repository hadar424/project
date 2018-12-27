#ifndef UNTITLED_IFCONDITION_H
#define UNTITLED_IFCONDITION_H

#include "ConditionParser.h"
#include "CommandExpression.h"

class IfCondition : public ConditionParser{
    int parametersNum;
public:
    IfCondition();
    int doCommand(vector<string>);

};

#endif //UNTITLED_IFCONDITION_H
