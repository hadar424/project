//
// Created by hadar on 12/21/18.
//

#include "IfCondition.h"

int IfCondition::doCommand(vector<string> array) {
    if (ConditionParser::doCommand(array) == 1) {
        parametersNum += doAllCommands();
    }
    return parametersNum + 1;
}

