#include "LoopCondition.h"

/*
 * Function Name: LoopCondition
 * Input: -
 * Output: -
 * Function Operation: constructor, initialize member
 */
LoopCondition::LoopCondition() {
    parametersNum = 1;
}

/*
 * Function Name: doCommand
 * Input: vector<string> array
 * Output: int
 * Function Operation: do all the commands while the condition is true
 */
int LoopCondition::doCommand(vector<string> array) {
    int firstLoop = 1;
    parametersNum = 1;
    // while the condition is true
    while (ConditionParser::doCommand(array) == 1) {
        // if first loop, update the parameters num
        if (firstLoop == 1) {
            firstLoop = 0;
            parametersNum += doAllCommands(array);
        } else {
            // otherwise, just do the commands
            doAllCommands(array);
        }
    }
    return parametersNum + 1;
}