#pragma once
#include <iostream>
class A {
    int a, b;
public:
    A(int a,int b);
   virtual ~A();
    int calcul();
};
class B :public A {
    int a, b;
public:
    B(int a, int b);
    ~B();
    int calcul();
};