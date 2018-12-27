#include "CalculateExpression.h"

/*
 * Function Name: shuntingYard
 * Input: string
 * Output: vector<string>
 * Function Operation: the function get an expression string in infix form
 * and convert it bt the shunting yard algorithm to a vector of strings in
 * postfix order.
 */
vector<string> CalculateExpression::shuntingYard(string myInfix){
    // initialize variables.
    vector<string> myQueue = {};
    vector<string> myStack = {};
    int minusFirst = 0;
    int IsDot = 0;
    string number;
    // run over all the chars in the string
    for (unsigned int i = 0; i < myInfix.length(); i++) {
        number = "";
        IsDot = 0;
        // cut an int or decimal number from the string
        while (IsDigit(myInfix[i]) || (myInfix[i] == '.')) {
            if((IsDot == 0) && (myInfix[i] == '.')) {
                IsDot = 1;
            }
            number+=myInfix[i];
            i++;
        }
        // push the number to the queue.
        if(number.length() != 0) {
            myQueue.push_back(number);
        }
        if ((!myQueue.empty()) || (myInfix[i] == '(')) {
            if (myInfix[i] == '+' || myInfix[i] == '-') {
                if (!myStack.empty()) {
                    if ((myStack.back().compare("*") == 0) ||
                    (myStack.back().compare("/") == 0)) {
                        // push operator from the top of the stack to the queue.
                        myQueue.push_back(myStack.back());
                        myStack.pop_back();
                    }
                }
                myStack.push_back(string(1, myInfix[i]));
            }
            if (myInfix[i] == '*' || myInfix[i] == '/' ) {
                if (!myStack.empty()) {
                    if ((myStack.back().compare("*") == 0) ||
                    (myStack.back().compare("/") == 0)) {
                        // push operator from the top of the stack to the queue.
                        myQueue.push_back(myStack.back());
                        myStack.pop_back();
                    }
                }
                myStack.push_back(string(1, myInfix[i]));
            }
            if ( myInfix[i] == '(') {
                myStack.push_back(string(1, myInfix[i]));
            }
            if (myInfix[i] == ')') {
                for (vector<string>::iterator it = myStack.end() - 1; it >= myStack.begin(); it--) {
                    if ((*it).compare("(") != 0) {
                        myQueue.push_back(*it);
                        myStack.pop_back();
                    }
                    else if ((*it).compare("(") == 0) {
                        myStack.pop_back();
                        break;
                    }
                }
            }
            // if the queue is empty its a negative number
        } else if(myInfix[i] == '-') {
            minusFirst = 1;
        }
    }
    while (!myStack.empty()) {
        myQueue.push_back(myStack.back());
        myStack.pop_back();
    }
    if(minusFirst == 1) {
        vector<string>::iterator it = myQueue.begin();
        myQueue.insert(it, "-");
    }
    return myQueue;
}

/*
 * Function Name: evaluatePostfix
 * Input: string
 * Output: Expression*
 * Function Operation: the function get a infix expression and convert it
 * to postfix using the shunting yard algorithm. the function evaluate the
 * postfix expression and return the output.
 */
Expression* CalculateExpression::evaluatePostfix(string exp) {
    // initialize variables
    exp = allCharsIsValid(exp);
    int minusFirst = 0;
    // call the shunting yard function
    vector<string> vec = shuntingYard(exp);
    // if there is a "-" at the first of the expression
    if(vec.front().compare("-") == 0) {
        minusFirst = 1;
    }
    stack<double> s;
    // run over all the strings in the vector
    for(vector<string>::iterator it = vec.begin(); it < vec.end(); it++) {
        // if it is an operator
        if(IsOperator((*it)[0])) {
            double result;
            double num2;
            // if it is a "-" for negative number
            if(minusFirst == 1) {
                // get the next string
                num2 = atof((*(it+1)).c_str());
                Number n2(num2);
                // create the negative number expression
                result = createExpression((*it)[0], &n2);
                it++;
                minusFirst = 0;
            } else {
                num2 = s.top();
                s.pop();
                // if it is a "-" for negative number
                if(IsNeg(s,vec) && ((*it)[0] == '-')) {
                    Number n2(num2);
                    result = createExpression((*it)[0], &n2);
                    // its a regular operator
                } else {
                    double num1 = s.top();
                    s.pop();
                    Number n1(num1);
                    Number n2(num2);
                    // calculate the expression
                    result = createExpression((*it)[0], &n1, &n2);
                }
            }
            //Push back result of operation on stack.
            s.push(result);
            // if it is a number
        } else if(IsNumber(*it)){
            double num = atof((*it).c_str());
            s.push(num);
        }
        vec.erase(it);
        it--;
    }
    if (s.empty()) {
        return nullptr;
    }
    // If expression is in correct format, Stack will finally have one element.
    // This will be the output.
    return new Number(s.top());
}

/*
 * Function Name: IsDigit
 * Input: char
 * Output: bool
 * Function Operation: the function get a char and check if it is numeric digit.
 */
bool CalculateExpression::IsDigit(char c) {
    if(c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

/*
 * Function Name: IsNumber
 * Input: string
 * Output: bool
 * Function Operation: the function get a string and check if it is a number.
 */
bool CalculateExpression::IsNumber(string s) {
    int dotCounter =0;
    // run over all the string chars
    for (unsigned int i = 0; i < s.length(); i++) {
        if(s[i] == '.') {
            dotCounter++;
            if(!IsDigit(s[i-1])) {
                return false;
            }
        } else if(s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    if(dotCounter >1) {
        return false;
    }
    // if all the chars are numeric digits and has max one dot its a number.
    return true;
}

/*
 * Function Name: allCharsIsValid
 * Input: string
 * Output: string
 * Function Operation: the function get a string and checks if it can be
 * calculated. throws exception if not, and erase unnecessary chars. return the
 * final string.
 */
string CalculateExpression::allCharsIsValid(string s) {
    // initialize variables
    int IsValid = 0;
    bool IsDelete;
    bool IsInsert;
    while(IsValid != 1) {
        IsDelete = false;
        IsInsert = false;
        //run over all the string chars
        for (unsigned int i = 0; i < s.length(); i++) {
            // first char cant be "*" or "/".
            if(((s[i] == '*') ||(s[i] == '/')) && (i == 0)) {
                throw invalid_argument("invalid expression");
            }
            // delete two consecutive "-" .
            if((s[i] == '-') && (s[i+1] == '-')) {
                s.erase(i,2);
                IsDelete = true;
                break;
            }
            // if its not one of this chars the string cant be calculated.
            if(!(IsDigit(s[i]) || IsOperator(s[i])|| s[i] == '.' ||
            s[i] == '(' || s[i] == ')')) {
                throw invalid_argument("invalid expression");
            }
            // must be a number before "/"
            if((IsOperator(s[i]) || s[i] == '(') && (s[i+1] == '/')) {
                throw invalid_argument("invalid expression");
            }
            // must be a number before "*"
            if((IsOperator(s[i]) || s[i] == '(') && (s[i+1] == '*')) {
                throw invalid_argument("invalid expression");
            }
            // erase unnecessary "+"
            if((IsOperator(s[i])) && (s[i+1] == '+')) {
                s.erase(i+1,1);
                IsDelete = true;
                break;
            }
            if(((IsOperator(s[i])) && (IsInsert) && (s[i] != '-')) ||
            ((IsInsert) && (i == s.length() -1))) {
                s.insert(i+1,")");
                IsInsert = true;
                break;
            }
            if (i != 0) {
                if (((s[i - 1] == '/') || (s[i - 1] == '*')) && (s[i] == '-')) {
                    s.insert(i, "(");
                    IsInsert = true;
                }
            }
        }
        if(!(IsDelete)||(IsInsert)) {
            IsValid = 1;
        }
    }
    // return the final string
    return s;
}

/*
 * Function Name: IsOperator
 * Input: char
 * Output: bool
 * Function Operation: the function get a char and check if it is an operator.
 */
bool CalculateExpression::IsOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    return false;
}

/*
 * Function Name: IsNeg
 * Input: stack<double>, vector<string>
 * Output: bool
 * Function Operation: the function checks if the "-" operator is for a
 * negative number or subtract two numbers.
 */
bool CalculateExpression::IsNeg(stack<double> s,vector<string> vec) {
    int nums = s.size();
    int counter = 0;
    vector<string> vec2 = vec;
    for(vector<string>::iterator it = vec2.begin(); it < vec2.end(); it++) {
        if (IsOperator((*it)[0])) {
            counter++;
        } else if (IsNumber(*it)) {
            nums++;
        }
    }
    // if the number of numbers in the stack equal to the numbers of operators.
    if (nums == counter) {
        return false;
    }
    return true;
}

/*
 * Function Name: createExpression
 * Input: char, Expression*, Expression*
 * Output: double
 * Function Operation: the function perform an operation on two expressions
 * numbers and return the calculated output.
 */
double CalculateExpression::createExpression(char operation, Expression* num1, Expression* num2) {
    switch (operation) {
        case '+': {
            Plus plus(num1, num2);
            return plus.calculate();
        }
        case '-': {
            Minus minus(num1, num2);
            return minus.calculate();
        }
        case '*': {
            Mul mul(num1, num2);
            return mul.calculate();
        }
        case '/': {
            Div div(num1, num2);
            return div.calculate();
        }
        default: throw invalid_argument("operator doesnt exist");
    }
}

/*
 * Function Name: createExpression
 * Input: char, Expression*
 * Output: double
 * Function Operation: the function perform an operation on one expression
 * number and return the calculated output.
 */
double CalculateExpression::createExpression(char operation, Expression* num) {
    if(operation == '-') {
        Neg neg(num);
        return neg.calculate();
    }
    throw invalid_argument("operator doesnt exist");
}