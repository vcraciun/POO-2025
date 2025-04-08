#include "Header.h"
#include <iostream>

int main() //CTR + K + C/U
{
    Dictionar<int, int> int_dict;
    Dictionar<string, string> str;

    str["10"] = "hello";

    int_dict[10] = 21;
    int_dict[22] = 5;
    int_dict[6] = 11;
    int_dict[50] = 4;
    int_dict[15] = 10;
    int_dict[15] = 100;
    cout << int_dict.GetCapacity() << " " << int_dict.GetSize() << endl;
    int_dict.Print();
    
    int_dict[25] = 6;
    int_dict[1] = 9;
    int_dict[4] = 44;
    int_dict[43] = 95;
    int_dict[23] = 36;
    int_dict[32] = 22;
    cout << int_dict.GetCapacity() << " " << int_dict.GetSize() << endl;
    int_dict.Print();
    
    int_dict += {22, 90};
    (int_dict += {43, 1}) += {20, 43};
    cout << int_dict.GetCapacity() << " " << int_dict.GetSize() << endl;
    int_dict.Print();

    //for (int i = 0; i < 12; i++)
    //    int_dict = int_dict + {23 + i, 35 + i};
    //cout << int_dict.GetCapacity() << " " << int_dict.GetSize() << endl;
    //int_dict.Print();

    for (int i = 0; i < 10; i++)
        str[to_string(i + 100)] = "POO_" + to_string(i);
    for (int i = 0; i < 10; i++)
        str += {"str" + to_string(i + 10), "20_" + to_string(20 + i)};

    str.Print();
    
    return 0;
}
