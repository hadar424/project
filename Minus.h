#ifndef UNTITLED_MINUS_H
#define UNTITLED_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression *l, Expression *r) : BinaryExpression(l, r) {};
    double calculate();
};


#endif //UNTITLED_MINUS_H