//
// Created by sharon on 17/12/18.
//

#ifndef UNTITLED_BINARYEXPRESSION_H
#define UNTITLED_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression{
protected:
    Expression* left;
    Expression* right;
public:
    BinaryExpression(Expression*, Expression*);
    double calculate() {};
};


#endif //UNTITLED_BINARYEXPRESSION_H
