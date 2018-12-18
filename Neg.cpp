
#include "Neg.h"

Neg::Neg(Expression* num) : UnaryExpression(num) { }

double Neg::calculate() {
    return  (-1)* myExp->calculate();
}