#include "Plus.h"

/*
 * Function Name: calculate
 * Input: -
 * Output: -
 * Function Operation: calculate left-right
 */
double Plus::calculate() {
    return left->calculate() + right->calculate();
}