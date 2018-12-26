//
// Created by sharon on 17/12/18.
//

#ifndef UNTITLED_EXPRESSION_H
#define UNTITLED_EXPRESSION_H

#include <iostream>
using namespace std;

class Expression {
public:
    virtual double calculate() = 0;

    virtual ~Expression() {};
};


#endif //UNTITLED_EXPRESSION_H
