#pragma once
#include <windows.h>
#include <vector>
#include <iostream>
#include <map>
#include <intrin.h>
#include <Psapi.h>
#include <Shlwapi.h>
using namespace std;

#pragma warning (disable:4996)

#define CELL_SIZE 0x1000
#define MIN_MEM 0x100000
#define MAX_MEM 0x80000000

struct SPECS {
    BYTE* VA;
    DWORD size;
};

class Scanner
{
    map<size_t, pair<int, string>> cells;

    friend void Traversal(Scanner* inst);
    bool CheckAccess(size_t addr);
    SPECS Specs(BYTE* buffer, bool me);
    char* GetSomething(BYTE* mod_base, BYTE* addr);
    char** GetData(int& count);
    friend int Evaluate(Scanner* inst);
public:
    Scanner();
};

