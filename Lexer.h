#ifndef PROJECT_LEXER_H
#define PROJECT_LEXER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MyLexer {
   string fileName;
   vector<string> vec;

public:
    MyLexer(string);
    vector<string> lexer();
    void lineToArray(string);
};


#endif //PROJECT_LEXER_H
