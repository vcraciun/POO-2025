#pragma once
#include <iostream>

class A {
private: int value;
public:
    void change(int tmp)
    {
        this->value = tmp;
    }
    void print()
    {
        std::cout << value << ' ' << &value << '\n';
    }
    A() {
        this->value = 0;
     }
};

class B: virtual public A{};
class C: virtual public A{};
class D : public C, public B {
private: int value;
public:
    void change(int tmp)
    {
        this->value = tmp;
    }
    void print()
    {
        std::cout << value << ' '<<&value<<'\n';
    }
    D() {
        this->value = 0;
    }
};