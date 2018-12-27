//
// Created by hadar on 12/23/18.
//

#include "CommandExpression.h"

CommandExpression::CommandExpression(Command* c){
    myCommand = c;
}

double CommandExpression::calculate() {
    return myCommand->doCommand(myCommandArray);
}

void CommandExpression::setCommandArray(vector<string> array) {
    myCommandArray = array;
}
