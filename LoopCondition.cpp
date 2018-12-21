//
// Created by hadar on 12/20/18.
//

#include "LoopCondition.h"


int LoopCondition::doCommand(vector<string> array) {
    int firstLoop = 1;
    while (conditionParser->doCommand(array) == 1) {
        if (firstLoop == 1) {
            firstLoop = 0;
            parametersNum += conditionParser->doAllCommands();
        } else {
            conditionParser->doAllCommands();
        }
    }
    return parametersNum + 1;
}