//
// Created by moshe on 12/04/2020.
//

#ifndef EX1_DOCUMENT_H
#define EX1_DOCUMENT_H
#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class Document {
public:
    std::vector<string> row;
    int currentLine=-1;
    Document();

    void goToLine(int num);
    void printAllDocument();
    void deleteRow(int num);
    void searchForwardAndMove(string str);
    void searchBeforeAndMove(string str);
    void replaceNewOld(string oldString,string newString);
    void appendTwoRow(int oneRow,int secondRow);
};


#endif //EX1_DOCUMENT_H
