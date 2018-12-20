//
// Created by sharon on 18/12/18.
//

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
#include "Expression.h"

using namespace std;

class CalculateExpression {
public:

    CalculateExpression() = default;

    vector<string> shuntingYard(string myInfix);

    // Function to evaluate Postfix expression and return output
    Expression* evaluatePostfix(string expression);

// Function to perform an operation and return output.
    double createExpression(char operation, Expression* operand1, Expression* operand2);

    double createExpression(char operation, Expression* operand1);

// Function to verify whether a character is operator symbol or not.
    bool IsOperator(char);

    bool IsNeg(stack<double> s,vector<string> vec);

    string allCharsIsValid(string s);

// Function to verify whether a character is numeric digit.
    bool IsDigit(char);

    bool IsNumber(string s);
};


#endif //UNTITLED_SHUNTINGYARD_H
