//
// Created by sharon on 17/12/18.
//

#include "Div.h"

Div::Div(Expression* l, Expression* r) : BinaryExpression(l, r){}

double Div::calculate() {
    if (right->calculate() == 0)
        throw runtime_error("can not divide in 0");
    return left->calculate() / right->calculate();
}