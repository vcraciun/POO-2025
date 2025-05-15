#include "Scanner.h"
//trebuie sa faceti build cu optimizarile disabled

int main()
{
    SetUnhandledExceptionFilter(GeneralException);
    MemoryTraversal m;
    m.print();
    exceptie1 ex1;
    try {
        void* mem = (void*)malloc(100);
        memset(mem, 0, 100);
        int ptr = *(int*)mem;
        char data = *(char*)ptr;        
        throw ex1;
    }
    catch (exception& e) {
        printf("Nu ar trebui sa vedem acest mesaj! Daca il vedem atunci a mers exceptia din C++");
        cout << e.what() << endl;
    }
}
