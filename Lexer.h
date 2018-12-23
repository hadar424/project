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
public:
    vector<string> lexer(string);
    void lineToArray(string);
    string removeSpaces(string);
    bool IsOperator(char);
    string backwardLoop(string, int);
    string forwardLoop(string, int);
};


#endif //PROJECT_LEXER_H
