#include "MyParser.h"

MyParser::MyParser(string file) {
    myLexer = new MyLexer();
    myTable = new SymbolTable();
    myData = new Data(myTable);

    commandArray = myLexer->lexer(file);
    commandMap = myData->getMap();
}

void MyParser::parser() {
    vector<string>::iterator it;
    while ((it = commandArray.begin()) < commandArray.end() - 1) {
        if((commandMap.find(*it))!= commandMap.end()) {
            CommandExpression *temp = commandMap.find(*it)->second;
            commandArray.erase(commandArray.begin());
            temp->setCommandArray(commandArray);
            it += (int)temp->calculate();
            commandArray.erase(commandArray.begin(), it);
        } else if ((*(it + 1)).compare("=") == 0) {
            it++;
            CommandExpression *temp = commandMap.find(*it)->second;
            temp->setCommandArray(commandArray);
            it += (int)temp->calculate();
            commandArray.erase(commandArray.begin(), it);
        } else {
            commandArray.erase(commandArray.begin(),it+1);
        }
    }
}

MyParser::~MyParser() {
    delete myLexer;
    delete myData;
    delete myTable;
}
