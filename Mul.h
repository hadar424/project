//
// Created by sharon on 17/12/18.
//

#ifndef UNTITLED_MUL_H
#define UNTITLED_MUL_H

#include "BinaryExpression.h"
class Mul : public BinaryExpression{
public:
    Mul(Expression*, Expression*);
    double calculate();
};


#endif //UNTITLED_MUL_H
