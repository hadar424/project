#ifndef UNTITLED_MUL_H
#define UNTITLED_MUL_H

#include "BinaryExpression.h"
class Mul : public BinaryExpression{
public:
    Mul(Expression *l, Expression *r) : BinaryExpression(l, r) {};
    double calculate();
};


#endif //UNTITLED_MUL_H
