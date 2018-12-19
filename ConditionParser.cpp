//
// Created by hadar on 12/19/18.
//

#include "ConditionParser.h"

int ConditionParser::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    left = setCondition(*it);
    it++;
    boolOperator = *it;
    it++;
    right = setCondition(*it);
    int result = checkCondition(boolOperator);
    return result;
}

double ConditionParser::setCondition(string s) {
    CalculateExpression* exp;
    SymbolTable* table;
    if(exp->evaluatePostfix(s) != NULL) {
        return exp->evaluatePostfix(s)->calculate();
    } else if(table->getValue(s) != NULL) {
        return table->getValue(s)->calculate();
    }
    throw invalid_argument("invalid condition");
}

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
