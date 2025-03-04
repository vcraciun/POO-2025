#include <iostream>
#include <windows.h>

//a se buildui pe 32 bit (x86) release, cu optimizari disabled

using namespace std;
int f_static(int a) {
    static int x = 1633771873;
    return (x >> 24)+a;
}

void modf() {
    unsigned char* y = (unsigned char*)f_static;
    int i = 0;
    int j = 0;
    while (true) {
        __try {
            if ((((int*)&y[i])[0]) == 1633771873) {
                j++;
                if (j == 2) {
                    ((int*)(y + i))[0] = 'CCCC';
                    break;
                }
            }
            i++;
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
            cout << "memorie invalida" << endl;
            break;
        }
    }
}

int main() {
    cout << (char)f_static(0)<<endl;
    modf();
    cout << (char)f_static(0) << endl;
    cout << (char)f_static(5) << endl;
    return 0;
}
