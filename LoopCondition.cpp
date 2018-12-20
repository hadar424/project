//
// Created by hadar on 12/20/18.
//

#include "LoopCondition.h"


int LoopCondition::doCommand(vector<string> array) {
    while (ConditionParser::doCommand(array) == 1) {
        parametersNum = doAllCommands();
    }
    return parametersNum + 1;
}