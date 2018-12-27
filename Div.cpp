#include "Div.h"

/*
 * Function Name: calculate
 * Input: -
 * Output: -
 * Function Operation: calculate left/right
 */
double Div::calculate() {
    // check if the right is 0
    if (right->calculate() == 0)
        throw runtime_error("can not divide in 0");
    return left->calculate() / right->calculate();
}