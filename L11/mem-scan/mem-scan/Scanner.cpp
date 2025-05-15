#include "Scanner.h"

void MemoryTraversal::print()
{
    for (auto& cell : cells)
    {
        if (!cell.second.second.second.empty())
            printf("addr:%08X size:%08X access:%s [%s]\n", cell.first, cell.second.first, cell.second.second.first.c_str(), cell.second.second.second.c_str());
    }
}

void MemoryTraversal::CheckAccess(size_t addr, char* flags)
{
    char read = 0;
    int last_index = 0;
    char writ = -1;
    unsigned char saved_byte = 0;

    __try {
        saved_byte = *(unsigned char*)addr;
        flags[last_index++] = 'R';
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return;
    }

    for (size_t start = addr; start < addr + CELL_SIZE; start++)
    {
        if (*(unsigned char*)start == ASM_RETURN)
        {
            __try {
                ((void(*)())start)();
                flags[last_index++] = 'E';
            }
            __except (EXCEPTION_EXECUTE_HANDLER) {

            }
            break;
        }
    }

    __try {
        *(unsigned char*)addr = saved_byte;
        flags[last_index++] = 'W';
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }
}

void MemoryTraversal::Traversal(MemoryTraversal* m)
{
    char acc[10] = { 0 };
    double percent;

    for (size_t s = MIN_MEM; s < MAX_MEM; s += CELL_SIZE)
    {
        percent = (double)s / (MAX_MEM / 100);
        printf("\rScanning address: ... %08X : %.2lf %%", s, percent);
        CheckAccess(s, acc);
        cells[s].second.first = acc;
        char buffer[256] = { 0 };
        int size = CELL_SIZE;
        GetModuleFileName((HMODULE)s, buffer, sizeof(buffer));
        if (strlen(buffer))
        {
            MODULEINFO modInfo;
            GetModuleInformation(GetCurrentProcess(), (HMODULE)s, &modInfo, sizeof(modInfo));                
            size = modInfo.SizeOfImage;
        }
        cells[s].second.first = size;
        cells[s].second.second = buffer;
    }
    printf("\n");
}

MemoryTraversal::MemoryTraversal()
{
    Traversal(this);
}

LONG WINAPI GeneralException(_EXCEPTION_POINTERS* ExceptionInfo)
{
    MessageBox(0, "Prgramul nu a crapat, dar ar fi trebuit!", "ATENTIE!", MB_OK);
    ExitProcess(0);
}
