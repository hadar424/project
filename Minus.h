//
// Created by sharon on 17/12/18.
//

#ifndef UNTITLED_MINUS_H
#define UNTITLED_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression*, Expression*);
    double calculate();
};


#endif //UNTITLED_MINUS_H
