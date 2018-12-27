#ifndef UNTITLED_PLUS_H
#define UNTITLED_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression{
public:
    Plus(Expression *l, Expression *r) : BinaryExpression(l, r) {};
    double calculate();
};


#endif //UNTITLED_PLUS_H