#include "AssignCommand.h"

/*
 * Function Name: AssignCommand
 * Input:
 * Output:
 * Function Operation: AssignCommand constructor
 */
AssignCommand::AssignCommand() {
    parametersNum = 1;
}

/*
 * Function Name: setSymbolTable
 * Input: SymbolTable* map
 * Output:
 * Function Operation: the function get a pointer to SymbolTable object
 * and set it as a member.
 */
void AssignCommand::setSymbolTable(SymbolTable* map) {
    myTable = map;
}

/*
 * Function Name: setServer
 * Input: Server*
 * Output:
 * Function Operation: the function get a pointer to Server object
 * and set it as a member.
 */
void AssignCommand::setServer(Server* server) {
    myServer = server;
}

/*
 * Function Name: setClient
 * Input: Client*
 * Output:
 * Function Operation: the function get a pointer to Client object
 * and set it as a member.
 */
void AssignCommand::setClient(Client* client) {
    myClient = client;
}

/*
 * Function Name: doCommand
 * Input: vector<string> array
 * Output: int
 * Function Operation: the function get a vector of strings in
 * form: var = value. the function calculate the value of the right string and
 * update it in the SymbolTable by the var name. In addition the function check
 * if the var need to be bind and if it is, the function send the new value
 * to the client(simulator).
 * the function returns the number of args it got.
 */
int AssignCommand::doCommand(vector<string> array) {
    Expression *e;
    Expression *e1;
    // initialize variables.
    parametersNum = 1;
    vector<string>::iterator it = array.begin();
    path = "";
    var = *it;
    value = 0;
    string serverPath;
    // if we need to send new value to the simulator or not.
    bool needChangeClient = false;
    // get the expression value from the SymbolTable.
    e1 = myTable->getValue(var);
    // if the var exist in the table
    if (e1 != nullptr) {
        // if the var has bind path
        if (myTable->getPath(var).compare("") != 0) {
            path = myTable->getPath(var);
            value = e1->calculate();
            // the new value need to be sent to the simulator.
            needChangeClient = true;
        }
    }
    if (e1) {
        delete e1;
    }
    e1 = nullptr;
    it += 2;
    bool isBind = false;
    CalculateExpression exp;
    // if there is in the right string bind path.
    if ((*it).compare("bind") == 0) {
        isBind = true;
        it++;
        e1 = myTable->getValue(*it);
        // if it is a var with bind path.
        if (e1 != nullptr) {
            path = myTable->getPath(*it);
            value = e1->calculate();
            // if it is just a bind path.
        } else {
            string newPath = cleanPath(*it);
            path = newPath;
            // get the current value from the simulator
            e1 = myServer->getValueFromMap(newPath);
            if (e1 != nullptr) {
                value = e1->calculate();
            } else {
                value = 0;
            }
        }
        if (e1) {
            delete e1;
        }
        // just a update of local variable in the table
    } else {
        // calculate the value from the string
        try {
            e = exp.evaluatePostfix(*it);
            value = e->calculate();
        } catch (exception &e2) {
            e1 = myTable->getValue(*it);
            if (e1 != nullptr) {
                value = e1->calculate();
            } else {
                value = myMakeItDouble.calculateValue(*it, myTable);
            }
        }
        if (e) {
            delete e;
        }
        if (e1) {
            delete e1;
        }
    }
    // update the value in the SymbolTable
    myTable->setValue(var, value, path);
    if (needChangeClient) {
       // updating the simulator
        myClient->setValueInMap(path, value);
    }
    if (isBind) {
        parametersNum++;
    }
    return parametersNum + 1;
}

/*
 * Function Name: cleanPath
 * Input: string
 * Output: string
 * Function Operation: the function get a path string and erase from it the
 * quotation marks in the start and the end of the string. returned the fixed
 * string.
 */
string AssignCommand::cleanPath(string s) {
    s.erase(0, 1);
    s.erase(s.length() - 1, s.length());
    return s;
}