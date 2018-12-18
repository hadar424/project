//
// Created by hadar on 12/18/18.
//

#include <iostream>
#include "CalculateExpression.h"
#include "Lexer.h"
#include "Parser.h"
int main() {
    MyLexer* lex = new MyLexer("test2.txt");
    MYParser* pars = new MYParser(lex->lexer());
    pars->parser();
/*
    string s = "1+(-5)";
    CalculateExpression* cal = new CalculateExpression();
    double num = cal->evaluatePostfix(s);
    cout<<num<<endl;*/
    return 0;
}
