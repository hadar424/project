#include "MakeItDouble.h"

/*
 * Function Name: MakeItDouble
 * Input: -
 * Output: -
 * Function Operation: constructor, initialize members
 */
MakeItDouble::MakeItDouble() {
    value = 0;
    var = "";
}

/*
 * Function Name: isOperator
 * Input: char c
 * Output: bool (true/false)
 * Function Operation: if operator, return true. otherwise, return false.
 */
bool MakeItDouble::isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
        return true;
    }
    return false;
}

/*
 * Function Name: calculateValue
 * Input: char c
 * Output: bool (true/false)
 * Function Operation: if operator, return true. otherwise, return false.
 */
double MakeItDouble::calculateValue(string myString, SymbolTable *map) {
    var = myString;
    value = 0;
    myTable = map;
    int lastOperator = -1;
    CalculateExpression exp;
    string copy = var;
    // run over the string
    for (unsigned int i = 0; i < (var = copy).length(); i++) {
        // check if current char is operator
        if (isOperator(copy[i])) {
            string left = copy.substr(lastOperator + 1, i - lastOperator - 1);
            int length = left.length();
            // check if the string before the operator is var from table
            if (isVar(left)) {
                e = myTable->getValue(left);
                string temp = to_string(e->calculate());
                copy.erase(lastOperator + 1, left.length());
                copy = copy.substr(0, lastOperator + 1) + temp +
                       copy.substr(lastOperator + 1);
                length = temp.length();
            }
            lastOperator = lastOperator + length + 1;
            i = lastOperator;
        }
        // if last char on string
        if (i == copy.length() - 1) {
            string left = copy.substr(lastOperator + 1);
            if (isVar(left)) {
                e = myTable->getValue(left);
                string temp = to_string(e->calculate());
                copy.erase(lastOperator + 1);
                copy = copy.substr(0, lastOperator + 1) + temp;
            }
        }
    }
    // try to calculate the string after replace vars in their values
    try {
        e = exp.evaluatePostfix(var);
        value = e->calculate();
        // return the result
        return value;
    }
    catch (exception &e1) {
        throw invalid_argument("invalid expression string");
    }
}

/*
 * Function Name: isVar
 * Input: string s
 * Output: Expression*
 * Function Operation: return the value of the var from the symbol table
 */
Expression *MakeItDouble::isVar(string s) {
    e = myTable->getValue(s);
    return e;
}

/*
 * Function Name: ~MakeItDouble
 * Input: -
 * Output: -
 * Function Operation: destructor.
 */
MakeItDouble::~MakeItDouble() {
    delete e;
}