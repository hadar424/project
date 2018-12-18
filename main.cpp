#include <iostream>
#include "Expression.h"
#include "Plus.h"
#include "Number.h"
#include "Mul.h"
#include "Div.h"
#include "ShuntingYard.h"

int main() {
    //Expression* e = new Plus(new Number(3), new Mul( new Div(new Number(4), new Number(2)) , new Number(5)));
    //e->calculate();
    string myExpression = " 2/(1-5)";
    ShuntingYard* lalal = new ShuntingYard();
    vector<char>* myPost= lalal->doPostfix(myExpression);
    for(vector<char>::iterator it = myPost->begin(); it < myPost->end(); it++) {
            cout << (*it);
    }
    return 0;
}