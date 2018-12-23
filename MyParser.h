#ifndef PROJECT_PARSER_H
#define PROJECT_PARSER_H

#include "Lexer.h"
#include "Data.h"

using namespace std;

class MyParser {
    MyLexer* myLexer = new MyLexer();
    vector<string> commandArray;
    unordered_map<string,CommandExpression*> commandMap;
    SymbolTable* myTable = new SymbolTable();
    Data* myData = new Data(myTable);

public:
    MyParser(string);
    void parser();
    ~MyParser();
};


#endif //PROJECT_PARSER_H
