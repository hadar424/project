#ifndef UNTITLED_UNARYEXPRESSION_H
#define UNTITLED_UNARYEXPRESSION_H

#include "Expression.h"

class UnaryExpression : public Expression {
protected:
    Expression *myNum = nullptr;
public:
    UnaryExpression(Expression *);
    double calculate() = 0;
};


#endif //UNTITLED_UNARYEXPRESSION_H