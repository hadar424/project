#include "Mul.h"

/*
 * Function Name: calculate
 * Input: -
 * Output: double
 * Function Operation: calculate left*right
 */
double Mul::calculate() {
    return left->calculate() * right->calculate();
}