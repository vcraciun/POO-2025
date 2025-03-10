#include "header1.h"

int my_secret_function(int a, int b)
{
    return a + b;
}

int myfa(int a, int b)
{
    return a * b * my_secret_function(a, b);
}