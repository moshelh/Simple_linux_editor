//
// Created by moshe on 12/04/2020.
//

#include "Document.h"


void Document::goToLine(int num) {
cout<<num+1<<"\t"<<this->row[num]<<endl;
currentLine=num;
}

void Document::printAllDocument() {

    for(const string &str:this->row){
        cout<<str<<endl;
    }
    currentLine=row.size()-1;
}

void Document::deleteRow(int num) {
    this->row.erase(row.begin()+num-1);
    this->currentLine=num;
}

void Document::searchForwardAndMove(string str) {

    for (int i = currentLine; i <row.size() ; ++i) {
        if(row[i].find(str)!=string::npos){
            cout<<row[i]<<endl;
            currentLine=i;
            return;
        }
    }
    currentLine= row.size();
}

void Document::searchBeforeAndMove(string str) {
    for (int i = 0; i <currentLine ; ++i) {
        if(row[i].find(str)!=string::npos){
            cout<<row[i]<<endl;
            currentLine=i;
            return;
        }
    }
    currentLine=0;
}

void Document::replaceNewOld(string oldString, string newString) {
    row[currentLine].replace(row[currentLine].find(oldString), sizeof(oldString)-1,newString);

}

void Document::appendTwoRow(int oneRow, int secondRow) {
this->row[oneRow].append(this->row[secondRow]);
this->row.erase(row.begin()+secondRow);
this->currentLine=oneRow;
}

Document::Document() {}


