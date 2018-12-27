#ifndef PROJECT_PARSER_H
#define PROJECT_PARSER_H

#include "CommandExpression.h"
#include "Lexer.h"
#include "Data.h"

using namespace std;

class MyParser {
    MyLexer *myLexer;
    vector<string> commandArray;
    unordered_map<string,CommandExpression*> commandMap;
    SymbolTable *myTable;
    Data *myData;

public:
    MyParser(string);
    void parser();
    ~MyParser();
};


#endif //PROJECT_PARSER_H
