/*
Dandu-se un folder cu trace-uri de executie, sa se construiasca codul C++ aferent fisierului main.cpp, astfel incat sa putem
lista la terminal, in formatul de mai jos, numele apelurilor de functii, cu frecventa mai mare de 50, impreuna cu frecventa efectiva si numarul de parametri a functiilor API:

_pin_trace_PID-1592_TID-5484.log
        KERNEL32.DLL:GetProcAddress 91 2
        KERNEL32.DLL:SetConsoleTextAttribute 74 2
        KERNEL32.DLL:VirtualQuery 151 3
        USER32.dll:wsprintfW 87 2
        VCRUNTIME140.dll:memset 108 3
        ntdll.dll:VerSetConditionMask 104 3
        ucrtbase.dll:__acrt_iob_func 1975 0
        ucrtbase.dll:__stdio_common_vfwprintf 2008 3
        ucrtbase.dll:__stdio_common_vswprintf_s 68 4
        ucrtbase.dll:fputc 1721 2
        ucrtbase.dll:free 60 1
        ucrtbase.dll:malloc 61 1
        ucrtbase.dll:strtok_s 65 3
        ucrtbase.dll:wcslen 103 1
_pin_trace_PID-2092_TID-2828.log
        KERNEL32.DLL:GetLocaleInfoA 57 4
        USER32.dll:GetDlgCtrlID 421907 1
_pin_trace_PID-4888_TID-7836.log
        KERNEL32.DLL:CompareStringOrdinal 1055 5
        KERNEL32.DLL:FormatMessageW 1053 7
        KERNEL32.DLL:GetProcAddress 60 2
        KERNEL32.DLL:GetProcessHeap 108 0
        KERNEL32.DLL:HeapFree 51 3
        USER32.dll:AddClipboardFormatListener 3785 1
        USER32.dll:DispatchMessageW 327 1
        USER32.dll:GetClassNameW 1055 3
        USER32.dll:GetMessageW 328 4
        USER32.dll:LoadStringW 120 4
        USER32.dll:SendMessageW 4324 4
        USER32.dll:SetWindowTextW 1053 2
        USER32.dll:TranslateAcceleratorW 654 3
        USER32.dll:TranslateMessage 327 1
        combase.dll:CoTaskMemFree 1065 1
        ntdll.dll:NtdllDefWindowProc_W 3722 4
        ntdll.dll:RtlInterlockedCompareExchange64 2966 0
        ucrtbase.dll:memcmp 303 3
        ucrtbase.dll:memcpy 303 3
_pin_trace_PID-6060_TID-7972.log
_pin_trace_PID-6152_TID-1892.log
        GDI32.dll:WidenPath 379987 1
        KERNEL32.DLL:GetLocaleInfoA 58 4
        KERNEL32.DLL:MultiByteToWideChar 78 6
        OLEAUT32.dll:SysAllocStringLen 78 2
        OLEAUT32.dll:SysFreeString 144 1
        OLEAUT32.dll:SysReAllocStringLen 478 3
        USER32.dll:CharUpperW 72 1
        USER32.dll:LoadStringA 116 4
        ntdll.dll:RtlEnterCriticalSection 263 1
        ntdll.dll:RtlLeaveCriticalSection 263 1
_pin_trace_PID-6440_TID-7628.log
        KERNELBASE.dll:InitializeCriticalSectionEx 79 3
_pin_trace_PID-7508_TID-6516.log
        KERNELBASE.dll:InitializeCriticalSectionEx 79 3
_pin_trace_PID-7664_TID-4212.log
        KERNELBASE.dll:InitializeCriticalSectionEx 79 3
_pin_trace_PID-7720_TID-5284.log
        KERNEL32.DLL:FileTimeToSystemTime 87 2
        KERNEL32.DLL:GetEnvironmentVariableA 153 3
        KERNEL32.DLL:GetProcAddress 912 2
        KERNEL32.DLL:GetTimeZoneInformation 87 1
        KERNEL32.DLL:SystemTimeToTzSpecificLocalTime 87 3
        USER32.dll:MapVirtualKeyW 96 2
        ucrtbase.dll:_mktime64 87 1
        ucrtbase.dll:malloc 63 1
_pin_trace_PID-7900_TID-6656.log
        KERNELBASE.dll:InitializeCriticalSectionEx 79 3
*/

// Exemplu Main
// Desi nu este necesar, trebuie sa utilizati o implementare de iterator pentru a itera obiecte de tip TraceFilter
int main()
{
    TraceFilter filter("traces");

    for (const auto& [fname, data] : filter)
    {
        cout << fname << endl;
        for (auto [api, extra] : data)
        {
            if (extra.count > 50)
                cout << "\t" << api << " " << extra.count << " " << extra.params << endl;
        }
    }

    return 0;
}


