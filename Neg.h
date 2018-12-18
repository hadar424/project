#ifndef UNTITLED_NEG_H
#define UNTITLED_NEG_H

#include "UnaryExpression.h"

class Neg : public UnaryExpression {
public:
    Neg(Expression*);
    double calculate();
};


#endif //UNTITLED_NEG_H
