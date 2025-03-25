#include "Header.h"

A::A(int a, int b) {
    this->a = a;
    this->b = b;

    std::cout << "(";
}
A::~A() {
    std::cout << ")";
}
int A::calcul()
{
    return a + b;
}

B::B(int a, int b):A(a,b)
{
    this->a = a;
    this->b = b;
    std::cout << "[";
}
B::~B()
{
    std::cout << "]";

}
int B::calcul()
{
    int c=a * b;
    a++;
    b++;
    return c;
}