#include "ConditionParser.h"

/*
 * Function Name: ConditionParser
 * Input:
 * Output:
 * Function Operation: ConditionParser constructor.
 */
ConditionParser::ConditionParser() {
    conditionParameters = 3;
}

/*
 * Function Name: setSymbolTable
 * Input: SymbolTable*
 * Output:
 * Function Operation: the function get a pointer to SymbolTable and set is as
 * a member.
 */
void ConditionParser::setSymbolTable(SymbolTable* s) {
    myTable =s;
}

/*
 * Function Name: setCommandMap
 * Input: unordered_map<string,CommandExpression*>
 * Output:
 * Function Operation: the function get an unordered_map and set is as a member.
 */
void ConditionParser::setCommandMap(unordered_map<string,CommandExpression*>
        map) {
    commandMap = map;
}

/*
 * Function Name: doCommand
 * Input: vector<string>
 * Output: int
 * Function Operation: the function get vector of strings, the 3 first strings
 * are represent the condition. the function check if the condition is
 * true (returned 1) or false (returned 0).
 */
int ConditionParser::doCommand(vector<string> array) {
    MakeItDouble makeItDouble;
    vector<string>::iterator it = array.begin();
    try {
        left = makeItDouble.calculateValue(*it, myTable);
    } catch (exception &e) {
        throw invalid_argument("left is invalid expression string");
    }
    it++;
    boolOperator = *it;
    it++;
    try {
        right = makeItDouble.calculateValue(*it, myTable);
    } catch (exception &e) {
        throw invalid_argument("right is invalid expression string");
    }
    it++;
    array.erase(array.begin(),it);
    int result = checkCondition(boolOperator);
    return result;
}

/*
 * Function Name: checkCondition
 * Input: string
 * Output: int
 * Function Operation: the function get a condition as string. and checks
 * if the candition is true (returned 1) or false (returned 0).
 */
int ConditionParser::checkCondition(string s) {
    if(s.compare(">=") == 0) {
        if(left >= right) {
            return 1;
        }
    } else if(s.compare("<=") == 0) {
        if(left <= right) {
            return 1;
        }
    } else if(s.compare("==") == 0) {
        if(left == right) {
            return 1;
        }
    } else if(s.compare("<") == 0) {
        if(left < right) {
            return 1;
        }
    } else if(s.compare(">") == 0) {
        if (left > right) {
            return 1;
        }
    } else if(s.compare("!=") == 0) {
        if(left != right) {
            return 1;
        }
    } else {
        throw invalid_argument("invalid condition");
    }
    return 0;
}

/*
 * Function Name: doAllCommands
 * Input: (vector<string>
 * Output: int
 * Function Operation: the function get a vector of strings and when it find a
 * command by the commands map, it calls to his "doCommand" function.
 * the function returns the sum of all the doCommands outputs.
 */
int ConditionParser::doAllCommands(vector<string> array) {
    vector<string>::iterator iter = array.begin();
    Expression *e;
    iter += 3;
    // remove tje condition
    array.erase(array.begin(), iter);
    int counter =0;
    int varsInCommend =0;
    vector<string>::iterator it;
    CommandExpression *temp;
    // run over the command list till the "}" sign
    while (*(it = array.begin()) != "}") {
        // if it founds a command
        if((commandMap.find(*it))!= commandMap.end()) {
            temp = commandMap.find(*it)->second;
            array.erase(array.begin());
            temp->setCommandArray(array);
            varsInCommend = temp->calculate();
            it+= varsInCommend;
            counter+=varsInCommend;
            array.erase(array.begin(), it);
            // if it founds a var exist in the table.
        } else {
            e = myTable->getValue(*it);
            if (e != nullptr) {
                temp = commandMap.find("=")->second;
                temp->setCommandArray(array);
                varsInCommend = temp->calculate();
                it += varsInCommend;
                counter += varsInCommend;
                array.erase(array.begin(), it);
            } else {
                counter++;
                array.erase(array.begin(), it + 1);
            }
            if (e) {
                delete e;
            }
        }
    }
    return counter + conditionParameters;
}