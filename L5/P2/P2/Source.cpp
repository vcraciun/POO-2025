#include "String.h"
int main()
{
    String s1 = "He";
    String s2 = "l";
    String s3 = String(0) * 2;          //codul ascii '0' de 2 ori
    String s4 = "P";
    
    String s5 = s1.operator+(s2) * 2 + s3 + " World of " + s4 + s3 + "!";  
    //concatenare
    int val = (int)s3;                  //cast la int
    String s6 = s1;
    s6 = s6 + s2 + s4 + "!";
    String s7 = s5(2);                  //conversie bytes din s5 la baza 2, in s7, cu spatii intre secvente de 8 biti
    /*String s8 = s5(10);                 //conversie la baza 10
    String s9 = s5(16);                 //conversie la baza 16

    cout << s5 << endl;
    cout << s3 << " = " << val << endl;
    cout << s6 << endl;
    cout << s7 << endl;
    cout << s8 << endl;
    cout << s9 << endl;

    char c1 = s5[7];
    char c2 = s3[1];
    char c3 = s5[7];
    cout << c1 << c2 << c2 << c3 << endl;

    String s10 = s5(0, 10);             //sub-string incepand cu index 0 in s5, 10 caractere
    s10[0] = s5[7];
    s10[4] = 32;
    s10[5] = 'd';
    s10[6] = s5[8];
    s10[7] = 'n';
    s10[8] = s5[1];
    s10[9] = s5[19];
    cout << s10 << endl;
    */
    return 0;
}

/*-----------------------------------------------------------------
Hell00 World of P00!
00 = 0
HelP!
1001000 1100101 1101100 1101100 110000 110000 100000 1010111 1101111 1110010 1101100 1100100 100000 1101111 1100110 100000 1010000 110000 110000 100001
72 101 108 108 48 48 32 87 111 114 108 100 32 111 102 32 80 48 48 33
48 65 6c 6c 30 30 20 57 6f 72 6c 64 20 6f 66 20 50 30 30 21
W00W
W
--------------------------------------------------------------------*/
