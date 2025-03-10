#include <iostream>

int u = 'ZZZZ';

int f_static(int a) {
    static int x = 1633771873;
    return x % 256 + a;
}

void modifx()
{
    unsigned char* mem = (unsigned char*)f_static;
    int k = 0;
    while (true)
    {
        int z = *(int*)mem;
        
        if (z == 'aaaa')
        {
            if (k == 0) k = 1;
            else {
                *(int*)mem = 'bbbb';
                break;
            }           
        }
        mem++;
    }
}
int main() {
    int a = 5;
    std::cout << (char)f_static(a) << std::endl;
    modifx();
    std::cout << (char)f_static(a) << std::endl;
    std::cout << (char)f_static(a + 2);
    printf("%d", u);
}