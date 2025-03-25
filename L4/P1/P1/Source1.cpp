#include "Header1.h"

Example::Example(int a, int b) {
    this->a = a;
    this->b = b;
    std::cout << "C";
}

    /*
Example::Example(const Example& t) {
    Arr = new int[2];
    Arr[0] = t.Arr[0];
    Arr[1] = t.Arr[1];
    std::cout << "c";
}
    */

Example::~Example() {
    std::cout << "D";
}

int Example::calcul() {
    return a * b;
}