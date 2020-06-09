//
// Created by moshe on 12/04/2020.
//

#ifndef EX1_EDITOR_H
#define EX1_EDITOR_H
#include "Document.h"


class Editor {
    Document document;
    int pointerOnDocument=0;
    void append();
    void appendBefore();
    void replace();
public:
    Editor();
    void loop();

};


#endif //EX1_EDITOR_H
