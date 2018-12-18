#include "Lexer.h"

MyLexer::MyLexer(string s) {
    fileName = s;
}

void MyLexer::lineToArray(string line) {
    while(line.length() != 0) {
        if (line.find(' ') != -1) {
            string temp = line.substr(0,line.find(' '));
            line.erase(0,line.find(' ') + 1);
            vec.push_back(temp);
        } else {
            vec.push_back(line);
            line.erase(0);
        }
    }
}

vector<string> MyLexer::lexer() {
    string line;
    fstream file;
    file.open(fileName, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            lineToArray(line);
        }
    }
    file.close();
    return vec;
}