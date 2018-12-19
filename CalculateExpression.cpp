
#include <cstring>
#include "CalculateExpression.h"

vector<string> CalculateExpression::shuntingYard(string myInfix){
    vector<string>* myQueue = new vector<string>;
    vector<string>* myStack = new vector<string>;
    int minusFirst = 0;
    int IsDot = 0;
    string number;
    for (int i = 0; i < myInfix.length(); i++) {
        number = "";
        IsDot = 0;
        while (IsDigit(myInfix[i]) || (myInfix[i] == '.')) {
            if((IsDot == 0) && (myInfix[i] == '.')) {
                IsDot = 1;
            }
            number+=myInfix[i];
            i++;
        }
        if(number.length() != 0) {
            myQueue->push_back(number);
        }
        if ((myQueue->size() > 0) || (myInfix[i] == '(')) {
            if (myInfix[i] == '+' || myInfix[i] == '-') {
                if (myStack->size() > 0) {
                    if ((myStack->back().compare("*") == 0) || (myStack->back().compare("/") == 0)) {
                        myQueue->push_back(myStack->back());
                        myStack->pop_back();
                    }
                }
                myStack->push_back(string(1,myInfix[i]));
            }
            if (myInfix[i] == '*' || myInfix[i] == '/' ) {
                if (myStack->size() > 0) {
                    if ((myStack->back().compare("*") == 0) || (myStack->back().compare("/") == 0)) {
                        myQueue->push_back(myStack->back());
                        myStack->pop_back();
                    }
                }
                myStack->push_back(string(1,myInfix[i]));
            }
            if ( myInfix[i] == '(') {
                myStack->push_back(string(1,myInfix[i]));
            }
            if (myInfix[i] == ')') {
                for(vector<string>::iterator it = myStack->end() - 1; it >= myStack->begin(); it--) {
                    if ((*it).compare("(") != 0) {
                        myQueue->push_back(*it);
                        myStack->pop_back();
                    }
                    else if ((*it).compare("(") == 0) {
                        myStack->pop_back();
                        break;
                    }
                }
            }
        } else if(myInfix[i] == '-') {
            minusFirst = 1;
        }
    }
    while (myStack->size() != 0) {
        myQueue->push_back(myStack->back());
        myStack->pop_back();
    }
    if(minusFirst == 1) {
        vector<string> ::iterator it = myQueue->begin();
        myQueue->insert(it,"-");
    }
    return *myQueue;
}


// Function to evaluate Postfix expression and return output
Expression* CalculateExpression::evaluatePostfix(string exp) {
    exp = allCharsIsValid(exp);
    int minusFirst = 0;
    vector<string> vec = shuntingYard(exp);
    if(vec.front().compare("-") == 0) {
        minusFirst = 1;
    }
    stack<double> s;
    for(vector<string>::iterator it = vec.begin(); it < vec.end(); it++) {
        if(IsOperator((*it)[0])) {
            double result;
            double num2;
            if(minusFirst == 1) {
                num2 = atof((*(it+1)).c_str());
                result = createExpression((*it)[0],new Number(num2));
                it++;
            } else {
                num2 = s.top();
                s.pop();
                if(IsNeg(s,vec) && ((*it)[0] == '-')) {
                    result = createExpression((*it)[0],new Number(num2));
                } else {
                    double num1 = s.top();
                    s.pop();
                    result = createExpression((*it)[0],  new Number(num1),  new Number(num2));
                }
            }
            //Push back result of operation on stack.
            s.push(result);
        } else if(IsNumber(*it)){
            double num = atof((*it).c_str());
            s.push(num);
        }
        vec.erase(it);
        it--;
    }
    if(s.size() == 0) {
        return NULL;
    }
    // If expression is in correct format, Stack will finally have one element. This will be the output.
    return new Number(s.top());
}

// Function to verify whether a character is numeric digit.
bool CalculateExpression::IsDigit(char c) {
    if(c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

bool CalculateExpression::IsNumber(string s) {
    int dotCounter =0;
    for(int i=0;i < s.length(); i++) {
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
    return true;
}

string CalculateExpression::allCharsIsValid(string s) {
    int IsValid = 0;
    bool IsDelete;
    bool IsInsert;
    while(IsValid != 1) {
        IsDelete = false;
        IsInsert = false;
        for(int i=0;i < s.length(); i++) {
            if(((s[i] == '*') ||(s[i] == '/')) && (i == 0)) {
                throw invalid_argument("invalid expression");
            }
            if((s[i] == '-') && (s[i+1] == '-')) {
                s.erase(i,2);
                IsDelete = true;
                break;
            }
            if(!(IsDigit(s[i]) || IsOperator(s[i])|| s[i] == '.' || s[i] == '(' || s[i] == ')')) {
                throw invalid_argument("invalid expression");
            }
            if((IsOperator(s[i]) || s[i] == '(') && (s[i+1] == '/')) {
                throw invalid_argument("invalid expression");
            }
            if((IsOperator(s[i]) || s[i] == '(') && (s[i+1] == '*')) {
                throw invalid_argument("invalid expression");
            }
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
            if(((s[i-1] == '/') || (s[i-1] == '*')) && (s[i] == '-')) {
                s.insert(i,"(");
                IsInsert = true;
            }
        }
        if(!(IsDelete)||(IsInsert)) {
            IsValid = 1;
        }
    }
    return s;
}

// Function to verify whether a character is operator symbol or not.
bool CalculateExpression::IsOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    return false;
}

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
    if (nums == counter) {
        return false;
    }
    return true;
}

// Function to perform an operation and return output.
double CalculateExpression::createExpression(char operation, Expression* num1, Expression* num2) {
    switch (operation) {
        case '+': {
            Expression *plus = new Plus(num1, num2);
            return plus->calculate();
        }
        case '-': {
            Expression* minus = new Minus(num1,num2);
            return minus->calculate();
        }
        case '*': {
            Expression *mul = new Mul(num1, num2);
            return mul->calculate();
        }
        case '/': {
            Expression* div = new Div(num1,num2);
            return div->calculate();
        }
        default: throw invalid_argument("operator doesnt exist");
    }
}

double CalculateExpression::createExpression(char operation, Expression* num) {
    if(operation == '-') {
        Expression* neg = new Neg(num);
        return neg->calculate();
    }
    throw invalid_argument("operator doesnt exist");
}
