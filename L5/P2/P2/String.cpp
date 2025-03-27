#include "String.h"

String::String(const char* str) {
    this->sir = str;
}
String::String(int numar) {
    this->sir = std::to_string(numar);
}
String String::operator*(int nr) {
    String sir_nou = "";
    for (int i = 0; i < nr; i++)
        sir_nou.sir += sir;
    return sir_nou;
}
String String::operator+(const String& s)
{
    String sir_nou = "";
    sir_nou.sir += sir;
    sir_nou.sir += s.sir;
    return sir_nou;
    
}
String String::operator+(const char* s)
{
    String sir_nou = "";
    sir_nou.sir+=sir;
    sir_nou.sir += s;
    return sir_nou;
 }

String :: operator int() {
    return atoi(sir.c_str());
}

String String :: operator()(int baza){
    char buffer[9];
    String sir_nou = " ";
    for (int i = 0; i < sir.size(); i++) {
        itoa(sir[i],buffer , baza);
        sir_nou.sir += buffer;
}
}