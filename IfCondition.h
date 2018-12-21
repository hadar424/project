//
// Created by hadar on 12/21/18.
//

#ifndef UNTITLED_IFCONDITION_H
#define UNTITLED_IFCONDITION_H

#include "ConditionParser.h"

class IfCondition : public ConditionParser{
    int parametersNum = 3;
    ConditionParser* conditionParser;
public:
    IfCondition(ConditionParser* c) {
        conditionParser=c;
    }
    int doCommand(vector<string>);
};

#endif //UNTITLED_IFCONDITION_H
