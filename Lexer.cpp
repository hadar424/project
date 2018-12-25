#include "Lexer.h"

void MyLexer::lineToArray(string line) {
    line = removeSpaces(line);
    while(line.length() != 0) {
        if (line.find(' ') != -1) {
            string temp = line.substr(0,line.find(' '));
            line.erase(0,line.find(' ') + 1);
            if(temp.length() > 0) {
                vec.push_back(temp);
            }
        } else {
            vec.push_back(line);
            line.erase(0);
        }
    }
}

vector<string> MyLexer::lexer(string fileName) {
    string line;
    fstream file;
    file.open(fileName, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            lineToArray(line);
            vec.push_back("\\n");
        }
    }
    file.close();
    return vec;
}

string MyLexer::removeSpaces(string s) {
    string command = "";
    if (s.find(' ') != -1) {
        command = s.substr(0, s.find(' ') + 1);
        s.erase(0, s.find(' '));
    }
    for(int i=0; i <s.length(); i++) {
        if(IsOperator(s[i])) {
            if (i != 0) {
                s = forwardLoop(s, i);
                s = backwardLoop(s, i);
            } else {
                s.erase(0, 1);
            }
        }
    }
    command += s;
    return command;
}

bool MyLexer::IsOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
        return true;
    }
    return false;
}

bool MyLexer::IsBoolOperator(char c) {
    if (c == '=' || c == '!' || c == '<' || c == '>' || c == '{') {
        return true;
    }
    return false;
}

string MyLexer::backwardLoop(string s, int i) {
    i--;
    while((IsOperator(s[i]) == false) && (i != 0)) {
        if(s[i] == ' ') {
            if (IsBoolOperator(s[i - 1])) {
                break;
            }
            s.erase(i,1);
        } else {
            if(s[i] == ',') {
                s.replace(i,1," ");
            }
            break;
        }
        i--;
    }
    return s;
}

string MyLexer::forwardLoop(string s, int i) {
    i++;
    while((IsOperator(s[i]) == false) && (i < s.length())) {
        if(s[i] == ' ') {
            if (IsBoolOperator(s[i + 1])) {
                break;
            }
            s.erase(i,1);
        } else {
            break;
        }
        i++;
    }
    return s;
}