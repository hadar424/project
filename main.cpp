//
// Created by hadar on 12/18/18.
//

#include <iostream>
#include "MyParser.h"


int main(int argc, char *argv[]) {
    string fileName;
    if (argc > 0) {
        fileName = argv[1];
    }
    MyParser *pars = new MyParser(fileName);
    pars->parser();
    while (1);
}
