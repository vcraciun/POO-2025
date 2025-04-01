#include "Header.h"
int main() {
    Object* p = new Panel(3,3,30,10,"Panel",0x1C);
    Object* l = new Label(3, 3, "Label", 0x4F);
    Object* b = new Button(5, 5, "Button", 0x3E);
    p->Insert(l);
    p->Insert(b);
    p->Paint();
    return 0;
}