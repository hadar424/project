#include "Minus.h"

/*
 * Function Name: calculate
 * Input: -
 * Output: double
 * Function Operation: calculate left-right
 */
double Minus::calculate() {
    return left->calculate() - right->calculate();
}