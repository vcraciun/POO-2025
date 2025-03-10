#include "header2.h"

int my_secret_function(int a, int b)
{
    return a * b;
}

int myfb(int a, int b)
{
    return a + b + my_secret_function(a, b);
}