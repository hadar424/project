//
// Created by hadar on 12/20/18.
//

#include "LoopCondition.h"

LoopCondition::LoopCondition() {
    parametersNum = 1;
}

int LoopCondition::doCommand(vector<string> array) {
    int firstLoop = 1;
    parametersNum = 1;
    while (ConditionParser::doCommand(array) == 1) {
        if (firstLoop == 1) {
            firstLoop = 0;
            parametersNum += doAllCommands(array);
        } else {
            doAllCommands(array);
        }
    }
    return parametersNum + 1;
}