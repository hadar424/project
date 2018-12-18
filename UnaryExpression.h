//
// Created by hadar on 12/18/18.
//

#ifndef UNTITLED_UNARYEXPRESSION_H
#define UNTITLED_UNARYEXPRESSION_H

#include "Expression.h"

class UnaryExpression : public Expression {
protected:
    Expression *myExp;
public:
    UnaryExpression(Expression *);

    double calculate() {};
};


#endif //UNTITLED_UNARYEXPRESSION_H
