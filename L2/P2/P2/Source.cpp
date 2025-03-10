#include <iostream>

int f_static(int a) {
    static int x = 1633771873;
    return x % 256 + a;
}

int main() {
    int a=5;
    std:: cout << f_static(a)<<std::endl;
    std::cout << f_static(a)<<std::endl;
    std::cout << f_static(a+2);
   
}