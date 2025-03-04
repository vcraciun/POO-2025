#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <string>
#include <math.h>

typedef int (*fptr)(int, int);

using namespace std;

int AD(int a, int b)
{
    return a * b;
}

int AP(int a, int b)
{
    return a * a;
}

int AC(int a, int b)
{
    return pow(a, 2) * 3.14;
}

int Sum(int a, int b)
{
    return a + b;
}

int prod(int a, int b)
{
    return a * b;
}

int dif(int a, int b)
{
    return a - b;
}

int cat(int a, int b)
{
    return a / b;
}

int rest(int a, int b)
{
    return a % b;
}

int main()
{
    fptr functii[8] = { AD, AP, AC, Sum , prod , dif , cat , rest };
    srand(time(0));
    int x = 8;
    int y = 0;
    int a, b;
    int rez = 0;
    vector<string>numFunc = { "aria-dreptunghiului","aria-patratului","aria-cercului","Sum","Prod","Dif","Cat","Rest" };
    for(int i = 0; i < 100; i++)
        {   
            y = rand()%x;
            a = rand() % 100; 
            b=rand() % 100;
            rez = functii[y](a, b);
            printf("%s(%d, %d) = %d\n", numFunc[y].c_str(), a, b, rez);

         }
    




}