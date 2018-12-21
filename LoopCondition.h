//
// Created by hadar on 12/20/18.
//

#ifndef UNTITLED_LOOPCONDITION_H
#define UNTITLED_LOOPCONDITION_H

#include "ConditionParser.h"

class LoopCondition : public ConditionParser{
    int parametersNum = 3;
    ConditionParser* conditionParser;
public:
    LoopCondition(ConditionParser* c) {
        conditionParser=c;
    }
    int doCommand(vector<string>);
};


#endif //UNTITLED_LOOPCONDITION_H
