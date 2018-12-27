#ifndef UNTITLED_SHUNTINGYARD_H
#define UNTITLED_SHUNTINGYARD_H

#include "Neg.h"
#include "Plus.h"
#include "Number.h"
#include "Mul.h"
#include "Div.h"
#include "Minus.h"
#include <vector>
#include <string>
#include<iostream>
#include<stack>
#include <list>
#include "Expression.h"

using namespace std;

class CalculateExpression {

    bool IsDigit(char);
    bool IsNumber(string s);
    vector<string> shuntingYard(string myInfix);
    double createExpression(char operation, Expression* operand1, Expression* operand2);
    double createExpression(char operation, Expression* operand1);
    string allCharsIsValid(string s);
    bool IsOperator(char);
    bool IsNeg(stack<double> s,vector<string> vec);

public:
    // return pointer to expression (new Number) the caller should delete
    Expression *evaluatePostfix(string expression);
};


#endif //UNTITLED_SHUNTINGYARD_H
