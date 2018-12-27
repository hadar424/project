#ifndef UNTITLED_LOOPCONDITION_H
#define UNTITLED_LOOPCONDITION_H

#include "ConditionParser.h"

class LoopCondition : public ConditionParser{
    int parametersNum;
public:
    LoopCondition();
    int doCommand(vector<string>);
};


#endif //UNTITLED_LOOPCONDITION_H
