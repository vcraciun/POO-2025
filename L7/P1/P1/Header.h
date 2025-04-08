#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class A, class B>
class Dictionar
{
private:
    A* keys;
    B* values;
    int size;
    int capacity;

    void resize();
    
public:
    Dictionar();

    ~Dictionar();

    int GetCapacity();

    int GetSize();

    B& operator[] (A);
    Dictionar& operator+=(pair<A, B>);

    void Print();
};

template <class A, class B>
Dictionar<A, B>::Dictionar()
{
    keys = new A[10];
    values = new B[10];
    size = 0;
    capacity = 10;
}

template <class A, class B>
Dictionar<A, B>::~Dictionar()
{
    delete[] keys;
    delete[] values;
}

template <class A, class B>
int Dictionar<A, B>::GetSize()
{
    return size;
}

template <class A, class B>
int Dictionar<A, B>::GetCapacity()
{
    return capacity;
}

template<class A, class B>
void Dictionar<A,B>::resize() {
    if (size == capacity)
    {
        A* tmpKeys = keys;
        B* tmpValues = values;
        keys = new A[capacity * 2];
        values = new B[capacity * 2];
        capacity *= 2;
        for (int ind = 0; ind < size; ind++)
        {
            keys[ind] = tmpKeys[ind];
            values[ind] = tmpValues[ind];
        }
        delete[] tmpKeys;
        delete[] tmpValues;
    }
}

template <class A, class B>
B& Dictionar<A, B>::operator[](A key)
{
    for (int ind = 0; ind < size; ind++)
        if (key == keys[ind])
            return values[ind];

    resize();

    keys[size] = key;
    return values[size++];
}

template <class A, class B>
Dictionar<A, B>& Dictionar<A, B>::operator+=(pair<A, B> p)
{
    for (int ind = 0; ind < size; ind++)
        if (p.first == keys[ind])
            return *this;

    resize();
    keys[size] = p.first;
    values[size] = p.second;
    size++;
    return *this;
}

template <class A, class B>
void Dictionar<A, B>::Print()
{
    for (int ind = 0; ind < size; ind++)
        std::cout << '(' << keys[ind] << ':' << values[ind] << ")\n";
}