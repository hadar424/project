#include "IfCondition.h"

/*
 * Function Name: IfCondition
 * Input: -
 * Output: -
 * Function Operation: constructor, initialize member
 */
IfCondition::IfCondition() {
    parametersNum = 1;
}

/*
 * Function Name: doCommand
 * Input: vector<string> array
 * Output: int
 * Function Operation: do all the commands if the condition is true
 */
int IfCondition::doCommand(vector<string> array) {
    parametersNum = 1;
    // if the condition is true
    if (ConditionParser::doCommand(array) == 1) {
        parametersNum += doAllCommands(array);
    }
    return parametersNum + 1;
}
