//
// Created by sharon on 17/12/18.
//

#ifndef UNTITLED_DIV_H
#define UNTITLED_DIV_H


#include "BinaryExpression.h"

class Div : public BinaryExpression{
public:
    Div(Expression*, Expression*);
    double calculate();
};


#endif //UNTITLED_DIV_H
