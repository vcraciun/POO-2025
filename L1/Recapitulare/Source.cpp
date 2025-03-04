#include <stdio.h>

int main() {         //0x20 0x00
    short x[8] = { 97, 32, 32, '  ', 48, 0, 0, -1 }; //??
    char a = ((char*)x + 1)[14]; 
    char b = *(char*)(x + 2);
    short c = *((short*)&((char*)x + 1)[0] + 6);
    int d = ((int*)(x + 3) + 1)[0];
    int e = ((int*)(x + 3) + 1)[1];

    printf("%d\n", a); //-1
    printf("%c\n", b); //' '
    printf("%d\n", c); //0x00 0xFF -> 0xFF00
    printf("%d\n", d); //0
    printf("%X\n", e); //??FF

    return 0;
}