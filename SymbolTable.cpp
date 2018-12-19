//
// Created by hadar on 12/19/18.
//

#include "SymbolTable.h"

Expression* SymbolTable::getValue(string s) {
    Expression* exp = new Number(valueMap.find(s)->second);
    return exp;
}
void SymbolTable::setValue(string s,double num) {
    valueMap.insert(pair<string,double>(s,num));
    cout<< s + ":" + to_string(num)<< endl;
}