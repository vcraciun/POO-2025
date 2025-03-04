#include "header2.h"

int my_secret_function(int a, int b) {
    int c = a * b;
    return c;
}

int myfb(int a, int b) {
    int c = my_secret_function(a, b) - a;
    return c;
}