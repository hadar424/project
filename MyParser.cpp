#include "MyParser.h"

/*
 * Function Name: MyParser
 * Input: string file
 * Output: -
 * Function Operation: constructor. initialize members, start lexer.
 */
MyParser::MyParser(string file) {
    myLexer = new MyLexer();
    myTable = new SymbolTable();
    myData = new Data(myTable);
    commandMap = myData->getMap();
    commandArray = myLexer->lexer(file);
}

/*
 * Function Name: parser
 * Input: -
 * Output: -
 * Function Operation: loop over all the commands in the script, and do them.
 */
void MyParser::parser() {

    vector<string>::iterator it;
    CommandExpression *temp;
    // loop over all the commands
    while ((it = commandArray.begin()) < commandArray.end() - 1) {
        if((commandMap.find(*it)) != commandMap.end()) {
            temp = commandMap.find(*it)->second;
            commandArray.erase(commandArray.begin());
            temp->setCommandArray(commandArray);
            // execute the current command
            it += (int)temp->calculate();
            // get ready for next iteration
            commandArray.erase(commandArray.begin(), it);
        } else if ((*(it + 1)).compare("=") == 0) {
            // command '=' is special because it's not the first word in line
            it++;
            temp = commandMap.find(*it)->second;
            temp->setCommandArray(commandArray);
            // execute the current command
            it += (int)temp->calculate();
            // get ready for next iteration
            commandArray.erase(commandArray.begin(), it);
        } else {
            // if '\n'
            commandArray.erase(commandArray.begin(), it + 1);
        }
    }
}

/*
 * Function Name: ~MyParser
 * Input: -
 * Output: -
 * Function Operation: destructor.
 */
MyParser::~MyParser() {
    if (myLexer != nullptr) {
        delete myLexer;
    }
    if (myData != nullptr) {
        delete myData;
    }
    if (myTable != nullptr) {
        delete myTable;
    }
    commandArray.clear();
}