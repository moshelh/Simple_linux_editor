//
// Created by moshe on 12/04/2020.
//

#include "Editor.h"
void Editor::loop() {
    string row;
    while (getline(std::cin, row)){
            if(row=="a"){
                append();
            }else if(row=="i"){
                appendBefore();
            }else if(row=="c") {
                replace();
            }else if(row.at(0)=='/'){
                    string temp = row.substr(1);
                    document.searchForwardAndMove(temp);
            } else if (row.at(0)=='?'){
                document.searchBeforeAndMove(row.substr(1));
            } else if(row.substr(0,2)=="s/"){
                string temp=row.substr(2);
                temp=temp.replace(temp.length()-1,temp.length(),"");
                string delimiter="/";
                int findChar=temp.find(delimiter);
                string oldString=temp.substr(0,findChar);
                string newString=temp.substr(findChar+1);
                document.replaceNewOld(oldString,newString);
            } else if (row=="%p"){
                document.printAllDocument();
            }else if(row=="Q"){
                break;
            } else if((row.find(",")!=string::npos)&&(row.substr(row.length()-1)=="j")){
                string temp=row.replace(row.length()-1,row.length(),"");
                string delimiter=",";
                int findChar=temp.find(delimiter);
                int first=stoi(temp.substr(0,findChar));
                int second=stoi(temp.substr(findChar+1));
                document.appendTwoRow(first-1,second-1);
            }else if (row.at(row.length()-1)=='d') {
                 document.deleteRow(stoi(row.substr(0, row.length() - 1)));
            }else if(row.at(row.length()-1)=='n') {
                document.goToLine(stoi(row.substr(0,row.length()-1)) - 1);
            }
    }
}

void Editor::append() {
    string row;
    pointerOnDocument=document.currentLine+1;
    while (getline(std::cin, row)){
        if(row=="."){
            break;
        } else{
            document.row.insert(document.row.begin() +pointerOnDocument, row);
           pointerOnDocument++;
        }
    }
}

void Editor::appendBefore() {
    string row;
    pointerOnDocument=document.currentLine;
    while (getline(std::cin, row)){
        if(row=="."){
            break;
        } else{
            document.row.insert(document.row.begin() + pointerOnDocument, row);
           pointerOnDocument++;
        }
    }
}

void Editor::replace() {
    string row;
    bool first= true;
    while (getline(std::cin, row)){
        if(row=="."){
            break;
        } if(first){
            document.row[document.currentLine]=row;
            pointerOnDocument=document.currentLine+1;
            first= false;
        }else{
            document.row.insert(document.row.begin() + pointerOnDocument, row);
            pointerOnDocument++;
        }
    }
}

Editor::Editor() {

}


