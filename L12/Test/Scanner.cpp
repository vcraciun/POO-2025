#include "Scanner.h"

bool Scanner::CheckAccess(size_t addr)
{
    unsigned char acc = 0;

    __try {
        acc = *(unsigned char*)addr;
        return true;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }    
}

void Traversal(Scanner* inst)
{
    char buffer[256] = { 0 };

    for (size_t s = MIN_MEM; s < MAX_MEM; s += CELL_SIZE)
    {
        if (inst->CheckAccess(s))
        {
            memset(buffer, 0, sizeof(buffer));
            GetModuleFileName((HMODULE)s, buffer, sizeof(buffer));
            if (strlen(buffer))
            {
                MODULEINFO modInfo;
                GetModuleInformation(GetCurrentProcess(), (HMODULE)s, &modInfo, sizeof(modInfo));
                inst->cells[s].first = modInfo.SizeOfImage;
                inst->cells[s].second = buffer;
            }
        }
    }
}

Scanner::Scanner()
{
    Traversal(this);
    int result = Evaluate(this);
    if (!result)
        printf("PASSED");
    else
        printf("FAILED");
}

char** Scanner::GetData(int& count)
{
    char** result = (char**)malloc(cells.size() * sizeof(char*));
    memset(result, 0, cells.size() * sizeof(char*));

    for (auto it : cells)
    {
        IMAGE_DOS_HEADER* imdos = (IMAGE_DOS_HEADER*)it.first;
        IMAGE_NT_HEADERS* imnt = (IMAGE_NT_HEADERS*)((BYTE*)it.first + imdos->e_lfanew);
        if (imnt->FileHeader.Characteristics & IMAGE_FILE_DLL)
        {
            char* elem = PathFindFileName(it.second.second.c_str());
            result[count] = (char*)malloc(strlen(elem) + 1);
            strcpy((char*)result[count], elem);
            count++;
        }
    }

    return result;
}

SPECS Scanner::Specs(BYTE* buffer, bool me)
{
    SPECS result = { 0 };
    IMAGE_DOS_HEADER* imdos = (IMAGE_DOS_HEADER*)buffer;
    IMAGE_NT_HEADERS32* imnt = (IMAGE_NT_HEADERS32*)(buffer + imdos->e_lfanew);
    IMAGE_SECTION_HEADER* imsec = (IMAGE_SECTION_HEADER*)((BYTE*)imnt + sizeof(IMAGE_NT_HEADERS32));

    if (me)
    {
        result.VA = imsec[0].VirtualAddress + buffer;
        result.size = (imsec[0].Misc.VirtualSize / imnt->OptionalHeader.SectionAlignment + 1) * imnt->OptionalHeader.SectionAlignment;
    }
    else
    {
        result.VA = imsec[0].PointerToRawData + buffer;
        result.size = (imsec[0].SizeOfRawData / imnt->OptionalHeader.FileAlignment + 1) * imnt->OptionalHeader.FileAlignment;
    }

    return result;
}

char* Scanner::GetSomething(BYTE* mod_base, BYTE* addr)
{
    BYTE* mod_addr = 0;
    DWORD i;
    char* fname = 0;

    mod_addr = mod_base;

    IMAGE_DOS_HEADER* imdos = (IMAGE_DOS_HEADER*)mod_addr;
    IMAGE_NT_HEADERS* imnth = (IMAGE_NT_HEADERS*)(mod_addr + imdos->e_lfanew);
    DWORD rva_exports = imnth->OptionalHeader.DataDirectory[0].VirtualAddress;

    IMAGE_EXPORT_DIRECTORY* imexp = (IMAGE_EXPORT_DIRECTORY*)(imnth->OptionalHeader.DataDirectory[0].VirtualAddress + mod_addr);
    DWORD AddressOfNames = imexp->AddressOfNames;
    size_t AddressOfNamesVA = (size_t)(AddressOfNames + mod_addr);
    DWORD real_index;
    BYTE* current_addr;

    for (i = 0; i < imexp->NumberOfNames; i++)
    {
        fname = (char*)(((DWORD*)AddressOfNamesVA)[i] + mod_addr);
        real_index = (size_t)((WORD*)(imexp->AddressOfNameOrdinals + mod_addr))[i];
        current_addr = (BYTE*)(((DWORD*)(imexp->AddressOfFunctions + mod_addr))[real_index] + mod_addr);
        if (current_addr == addr)
            break;
    }

    return fname;
}

int Evaluate(Scanner* inst)
{
    int count = 0;    
    char** items = inst->GetData(count);    
    int diffs = 0;
    const char* filters[6] = {"vcp", "VCP", "vcr", "VCR", "ucr", "UCR"};
    
    for (int k = 0; k < count; k++)
    {
        bool skip = false;
        for (int j = 0; j < 6; j++)
        {
            if (strstr(items[k], filters[j]))
            {
                skip = true;
                break;
            }
        }
        if (skip)
            continue;

        printf("%s\n", items[k]);
        char fpath[MAX_PATH] = { 0 };
        HMODULE mod = GetModuleHandle(items[k]);
        GetModuleFileName(mod, fpath, MAX_PATH);
        HANDLE f = CreateFile(fpath, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
        if (f == INVALID_HANDLE_VALUE)
        {
            printf("cannot access [%s]\n", fpath);
            return 0;
        }
        DWORD size = GetFileSize(f, 0);
        DWORD read = 0;
        BYTE* buffer = (BYTE*)malloc(size);
        ReadFile(f, buffer, size, &read, 0);
        CloseHandle(f);
        SPECS m1 = inst->Specs(buffer, false);
        SPECS m2 = inst->Specs((BYTE*)mod, true);
        for (size_t i = 0; i < min(m1.size, m2.size); i++)
        {
            __try {
                if ((m1.VA[i] != m2.VA[i]) && (m2.VA[i] == 0xE9))
                {
                    diffs++;
                    char* name = inst->GetSomething((BYTE*)mod, m2.VA + i);
                    printf("%p: [%02X %02X %02X %02X %02X] <--> [%02X %02X %02X %02X %02X] : {%s}\n", m2.VA + i,
                        m1.VA[i + 0], m1.VA[i + 1], m1.VA[i + 2], m1.VA[i + 3], m1.VA[i + 4],
                        m2.VA[i + 0], m2.VA[i + 1], m2.VA[i + 2], m2.VA[i + 3], m2.VA[i + 4],
                        name);
                }
            }
            __except (EXCEPTION_EXECUTE_HANDLER) {
                break;
            }
        }
    }

    for (int i = 0; i < count; i++)
        free(items[i]);
    free(items);

    return diffs;
}
