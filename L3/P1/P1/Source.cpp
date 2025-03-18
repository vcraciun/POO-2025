#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
class MyClass
{
private:
    int var1;
    char str[8];
    int var2;
    char chr;
    static MyClass* inst;
	MyClass();
	~MyClass();
public:
    static  MyClass* GetInst()
    {
        if (inst == 0)
            inst = new MyClass();
        return inst;
    }

    static void freeInst()
    {
        delete inst;
    }

    void Print()
    {
        char* ptr = (char *) & var1;
        printf("%s\n", ptr);
    }
};

MyClass *MyClass::inst = 0;

MyClass::MyClass()
{
    var1 = 'aaaa';
    var2 = 'AAAA';

    memset(str, '8', sizeof(str));

    chr = 0;
}

MyClass::~MyClass()
{
}

class MyClass2 {

private:


public:
    MyClass2()
    {

        printf("Suntem In Constructor.\n");

    }

    ~MyClass2()
    {
        printf("Am Iesit Din Constructor.\n");
    }

};

int main()
{
    MyClass* a = MyClass::GetInst();

    a->Print();

    //printf("%d", sizeof(cls));
    *(int*)a = 'zzzz';

    a->Print();

    MyClass::freeInst();

    MyClass2 mc2;

    MyClass2* mc2d1 = new MyClass2();

    MyClass2* mc2d2 = (MyClass2*) malloc(sizeof(MyClass2));

    new(mc2d2)MyClass2();

    delete mc2d1;
    mc2d2->~MyClass2();
    free(mc2d2);
    

    return 0;
}