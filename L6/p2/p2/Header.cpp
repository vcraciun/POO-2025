#include "Header.h"
#include <windows.h>



void Object::Insert(Object* other) {
    other->x += this->x;
    other->y += this->y;
    child.push_back(other);
}

void Object::PaintChild() {
    for (auto i : child) {
        i->Paint();
    }
}

void Panel::Paint() {
    HANDLE hh = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hh, color);
   //SetConsoleCursorPosition(hh, { (short)x,(short)y });
    for (int i = 0; i < length; i++) {
        SetConsoleCursorPosition(hh, { (short)x,(short)(y+i) });
        if (i == 0) {
            printf("%s%*c", label.c_str(), width - label.size(), ' ');
        }
        else 
        printf("%*c", width, ' ');
    }
    SetConsoleTextAttribute(hh, 0x07);
    this->PaintChild();
}

void Label::Paint() {
    HANDLE hh = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hh, color);
    //SetConsoleCursorPosition(hh, { (short)x,(short)y });
        SetConsoleCursorPosition(hh, { (short)x,(short)(y) });
            printf("%s%*c", label.c_str(), width - label.size(), ' ');
    SetConsoleTextAttribute(hh, 0x07);
    this->PaintChild();
}

void Button::Paint() {
    HANDLE hh = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hh, color);
    //SetConsoleCursorPosition(hh, { (short)x,(short)y });
    SetConsoleCursorPosition(hh, { (short)x,(short)(y) });
    printf("%*c", width, ' ');
    SetConsoleCursorPosition(hh, { (short)x,(short)(y+1) });
    printf("  %s  ", label.c_str());
    SetConsoleCursorPosition(hh, { (short)x,(short)(y+2) });
    printf("%*c", width, ' ');
    SetConsoleTextAttribute(hh, 0x07);
    this->PaintChild();
}