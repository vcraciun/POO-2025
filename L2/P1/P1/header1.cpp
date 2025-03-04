#include "header1.h"

int my_secret_function(int a, int b) {
    int c = a + b;
    return c;
}

int myfa(int a, int b) {
    int c = a + my_secret_function(a, b);
    return c;
}