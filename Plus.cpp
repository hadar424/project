//
// Created by sharon on 17/12/18.
//

#include "Plus.h"

Plus::Plus(Expression* l, Expression* r) : BinaryExpression(l, r) {}

double Plus::calculate() {
    return left->calculate() + right->calculate();
}