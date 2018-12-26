//
// Created by hadar on 12/18/18.
//

#include <iostream>
#include "MyParser.h"


int main(int argc, char *argv[]) {
    string fileName;
    if (argc <= 1) {
        return 0;
    }
    fileName = argv[1];
    MyParser *pars = new MyParser(fileName);
    pars->parser();
    delete pars;
    return 0;
}
