#ifndef PROJECT_LEXER_H
#define PROJECT_LEXER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class MyLexer {
   vector<string> vec;
    void lineToArray(string);
    string removeSpaces(string);
    bool isOperator(char);
    bool isBoolOperator(char);
    string backwardLoop(string, int);
    string forwardLoop(string, int);

public:
    vector<string> lexer(string);
};


#endif //PROJECT_LEXER_H
