#pragma once
#include <string>

class String {
    std::string sir;
public:
    String(const char* str);
    String(int numar);
    String operator*(int nr);
    String operator+(const String& s);
    String operator+(const char* s);
    operator int();
    String operator()(int);
};
