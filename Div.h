#ifndef UNTITLED_DIV_H
#define UNTITLED_DIV_H

#include "BinaryExpression.h"

class Div : public BinaryExpression{
public:
    Div(Expression *l, Expression *r) : BinaryExpression(l, r) {};
    double calculate();
};


#endif //UNTITLED_DIV_H