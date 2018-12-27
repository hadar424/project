#include "BinaryExpression.h"

/*
 * Function Name: BinaryExpression
 * Input: Expression*, Expression*
 * Output:
 * Function Operation: BinaryExpression constructor.
 */
BinaryExpression::BinaryExpression(Expression* leftNum, Expression* rightNum){
    left = leftNum;
    right = rightNum;
}
