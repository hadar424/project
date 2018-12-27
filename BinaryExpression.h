#ifndef UNTITLED_BINARYEXPRESSION_H
#define UNTITLED_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression{
protected:
    Expression* left;
    Expression* right;
public:
    BinaryExpression(Expression*, Expression*);
    double calculate() = 0;
};


#endif //UNTITLED_BINARYEXPRESSION_H
