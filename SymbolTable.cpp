//
// Created by hadar on 12/19/18.
//

#include "SymbolTable.h"

Expression* SymbolTable::getValue(string s) {
    if((valueMap.find(s)) != valueMap.end()) {
        Expression* exp = new Number(valueMap.find(s)->second);
        return exp;
    } else {
        return NULL;
    }
}
void SymbolTable::setValue(string s,double num) {
    valueMap.insert(pair<string,double >(s,num));
    cout<<s +to_string(num) <<endl;
}

void SymbolTable::updateValue(string s,double num) {
    valueMap.find(s)->second = num;
    cout<<s +to_string(num) <<endl;
}

