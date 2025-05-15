#include <windows.h>
#include <vector>
#include <iostream>
#include <map>
#include <intrin.h>
#include <Psapi.h>
using namespace std;

#define ASM_RETURN 0xC3
#define CELL_SIZE 0x1000
#define MIN_MEM 0x100000
#define MAX_MEM 0x80000000

class exceptie1 : public exception
{
    virtual const char* what() const throw()
    {
        return "EROARE";
    }
};

class MemoryTraversal
{
    map<size_t, pair<int, pair<string, string>>> cells;

    void Traversal(MemoryTraversal* m);
    void CheckAccess(size_t addr, char* flags);
public:
    MemoryTraversal();
    void print();
};

LONG WINAPI GeneralException(_EXCEPTION_POINTERS* ExceptionInfo);
