#include "CommandExpression.h"

/*
 * Function Name: CommandExpression
 * Input: Command*
 * Output:
 * Function Operation:  CommandExpression constructor.
 */
CommandExpression::CommandExpression(Command* c){
    myCommand = c;
}

/*
 * Function Name: CommandExpression
 * Input:
 * Output: double
 * Function Operation: the function call the "doCommand" function of the
 * member command. returned double.
 */
double CommandExpression::calculate() {
    return myCommand->doCommand(myCommandArray);
}

/*
 * Function Name: setCommandArray
 * Input: vector<string>
 * Output:
 * Function Operation: the function get a strings vector of commands and set it
 * as a member.
 */
void CommandExpression::setCommandArray(vector<string> array) {
    myCommandArray = array;
}
