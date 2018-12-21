//
// Created by hadar on 12/20/18.
//

#include "LoopCondition.h"


int LoopCondition::doCommand(vector<string> array) {
    while (conditionParser->doCommand(array) == 1) {
        parametersNum += conditionParser->doAllCommands();
    }
    return parametersNum + 1;
}