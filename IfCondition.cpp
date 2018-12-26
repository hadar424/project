//
// Created by hadar on 12/21/18.
//

#include "IfCondition.h"

IfCondition::IfCondition() {
    parametersNum = 1;
}

int IfCondition::doCommand(vector<string> array) {
    parametersNum = 1;
    if (ConditionParser::doCommand(array) == 1) {
        parametersNum += doAllCommands(array);
    }
    return parametersNum + 1;
}

