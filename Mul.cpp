//
// Created by sharon on 17/12/18.
//

#include "Mul.h"

Mul::Mul(Expression* l, Expression* r) : BinaryExpression(l, r) {}

double Mul::calculate() {
    return left->calculate() * right->calculate();
}