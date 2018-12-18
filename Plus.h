//
// Created by sharon on 17/12/18.
//

#ifndef UNTITLED_PLUS_H
#define UNTITLED_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression{
public:
    Plus(Expression*, Expression*);
    double calculate();
};


#endif //UNTITLED_PLUS_H
