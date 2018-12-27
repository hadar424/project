#include "Lexer.h"

/*
 * Function Name: lineToArray
 * Input: string line
 * Output: -
 * Function Operation: enter each string from text to vector
 */
void MyLexer::lineToArray(string line) {
    // make the line valid (remove spaces)
    line = removeSpaces(line);
    string temp = "";
    // till the end of line
    while(line.length() != 0) {
        // if there is space in the line
        if (line.find(' ') != string::npos) {
            // check if first char is "
            if (line[0] == '"') {
                // save the string (format: "BLABLABLA")
                temp = line.substr(0, line.find('"', 1) + 1);
                line.erase(0, line.find('"', 1) + 1);
            } else {
                // if regular word, save till space
                temp = line.substr(0, line.find(' '));
                line.erase(0, line.find(' ') + 1);
            }
            // if temp is not empty string, enter to vector
            if(temp.length() > 0) {
                vec.push_back(temp);
            }
        } else {
            // end of line, enter the rest of line to vector
            vec.push_back(line);
            line.erase(0);
        }
    }
}

/*
 * Function Name: lexer
 * Input: string fileName
 * Output: vector<string>
 * Function Operation: make vector of string from the text
 */
vector<string> MyLexer::lexer(string fileName) {
    string line = "";
    fstream file;
    file.open(fileName, ios::in);
    if (file.is_open()) {
        // while there are more lines
        while (getline(file, line)) {
            // take care of one line from the text
            lineToArray(line);
            // push '\n' to know when we get to new line
            vec.push_back("\\n");
        }
    }
    file.close();
    // close the string vector
    return vec;
}

/*
 * Function Name: removeSpaces
 * Input: string s
 * Output: string
 * Function Operation: remove spaces from string
 */
string MyLexer::removeSpaces(string s) {
    string command = "";
    // save the first part
    if (s.find(' ') != string::npos) {
        command = s.substr(0, s.find(' ') + 1);
        s.erase(0, s.find(' ') + 1);
    }
    // loop over the rest of the line
    for (unsigned int i = 0; i < s.length(); i++) {
        // check if start of string
        if (s[i] == '"') {
            i = s.find('"', i + 1);
        }
        // check if operator
        if (IsOperator(s[i])) {
            if (i != 0) {
                // remove spaces (before and after the operator)
                s = forwardLoop(s, i);
                s = backwardLoop(s, i);
            } else {
                s.erase(0, 1);
            }
        }
    }
    // return the updated line
    command += s;
    return command;
}

/*
 * Function Name: isOperator
 * Input: char c
 * Output: bool (true/false)
 * Function Operation: check if the char is operator
 */
bool MyLexer::IsOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
        return true;
    }
    return false;
}

/*
 * Function Name: isBoolOperator
 * Input: char c
 * Output: bool (true/false)
 * Function Operation: check if the char is bool operator
 */
bool MyLexer::IsBoolOperator(char c) {
    if (c == '=' || c == '!' || c == '<' || c == '>' || c == '{') {
        return true;
    }
    return false;
}

/*
 * Function Name: backwardLoop
 * Input: string s, int i
 * Output: string
 * Function Operation: fix the sub string (from operator and backward)
 */
string MyLexer::backwardLoop(string s, int i) {
    i--;
    // loop over the line till operator / beginning of line
    while ((IsOperator(s[i]) == false) && (i != 0)) {
        // if this char is space
        if(s[i] == ' ') {
            // check if the next char is boolean operator
            if (IsBoolOperator(s[i - 1])) {
                // if it is, do not erase the space
                break;
            }
            // otherwise, erase the space
            s.erase(i, 1);
        } else {
            // if this char is ',' - replace with ' '
            if(s[i] == ',') {
                s.replace(i, 1, " ");
            }
            break;
        }
        i--;
    }
    // return the sub string fix
    return s;
}

/*
 * Function Name: forwardLoop
 * Input: string s, int i
 * Output: string
 * Function Operation: fix the sub string (from operator and forward)
 */
string MyLexer::forwardLoop(string s, int i) {
    i++;
    // loop over the line till operator / end of line
    while ((IsOperator(s[i]) == false) && ((unsigned int) i < s.length())) {
        // if this char is space
        if(s[i] == ' ') {
            // check if the next char is boolean operator
            if (IsBoolOperator(s[i + 1])) {
                // if it is, do not erase the space
                break;
            }
            // otherwise, erase the space
            s.erase(i, 1);
        } else {
            break;
        }
        i++;
    }
    // return the sub string fix
    return s;
}