//
// Created by hadar on 12/18/18.
//

#include <iostream>
#include "CalculateExpression.h"
#include "Lexer.h"
#include "Parser.h"
#include "SymbolTable.h"


int main() {

    MyLexer* lex = new MyLexer("test.txt");
    vector<string> v = lex->lexer();
    MYParser* pars = new MYParser(v);
    pars->parser();

 /*   string s = "+-5";
    CalculateExpression* c;
    double n = c->evaluatePostfix(s)->calculate();
    cout<< n<< endl;*/
    return 0;
}
