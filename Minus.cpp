//
// Created by sharon on 17/12/18.
//

#include "Minus.h"

Minus::Minus(Expression* l, Expression* r) : BinaryExpression(l, r){}

double Minus::calculate() {
    return left->calculate() - right->calculate();
}