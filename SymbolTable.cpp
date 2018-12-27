#include "SymbolTable.h"

/*
 * Function Name: getValue
 * Input: string s
 * Output: Expression*
 * Function Operation: get value of var
 */
Expression* SymbolTable::getValue(string s) {
    Expression *exp = nullptr;

    // check if the var exists (defined)
    if((valueMap.find(s)) != valueMap.end()) {
        Expression *e;
        e = myServer->getValueFromMap(valueMap.find(s)->second.path);
        // check if exist in server map
        if (myServer->getValueFromMap(valueMap.find(s)->second.path) != nullptr) {
            exp = e;
        } else {
            exp = new Number(valueMap.find(s)->second.value);
        }
        if (e) {
            delete e;
        }
    }

    // return the expression
    return exp;
}

/*
 * Function Name: setServer
 * Input: Server* server
 * Output: -
 * Function Operation: set server
 */
void SymbolTable::setServer(Server *server) {
    myServer = server;
}

/*
 * Function Name: getPath
 * Input: string var
 * Output: string
 * Function Operation: return the path of the var
 */
string SymbolTable::getPath(string var) {
    string path = "";
    // search in value map
    if ((valueMap.find(var)) != valueMap.end()) {
        path = valueMap.find(var)->second.path;
    }
    return path;
}

/*
 * Function Name: setValue
 * Input: string s, double num, string path
 * Output: -
 * Function Operation: set value and path in map
 */
void SymbolTable::setValue(string s, double num, string path) {
    // if new
    if (getValue(s) == nullptr) {
        struct myParams *params = new myParams();
        // set value and map
        params->value = num;
        params->path = path;
        // insert to value map
        valueMap.insert(make_pair(s, *params));
    } else {
        // if already exist, update
        updateValueAndPath(s, num, path);
    }

}

/*
 * Function Name: updateValueAndPath
 * Input: string s, double num, string path
 * Output: -
 * Function Operation: update value and path in map
 */
void SymbolTable::updateValueAndPath(string s, double num, string path) {
    valueMap.find(s)->second.value = num;
    valueMap.find(s)->second.path = path;
}