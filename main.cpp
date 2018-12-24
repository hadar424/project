//
// Created by hadar on 12/18/18.
//

#include <iostream>
#include "MyParser.h"


int main() {
    MyParser *pars = new MyParser("test.txt");
    pars->parser();
    while (1);
}
