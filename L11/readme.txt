Sa scrie un program C++ care sa utilizeze exceptii, astfel incat sa avem urmatoarele functionalitati:
1. listam modulele incarcate in proces si zonele de memorie importante, plus drepturi de acces R/W/E, doar folosind exceptii:
   a) modul este orice DLL pentru care o adresa de memorie raspunde cu un buffer valid, la apelul GetModuleFileName(adresa)
   b) stiva (adresa, dimensiune)
   c) heap prealocat (adresa, dimensiune)
   d) aplicatia noastra [main module] (adresa, dimensiune)
   e) thread environment block (fs:0x18)

2. inainte sa iesim din main() incercam un apel la try-catch care crapa, insa aplicatia nu trebuie sa crape ci sa iasa cu un mesaj

3. sa se scrie pe disk orice modul care nu face parte din multimea {aplicatia_curenta, Windows}

Exemplu de output:
addr:005D2000 size:00006000 access:R [ENVIRONMENT]
addr:006FA000 size:00008000 access:R [STACK]
addr:00FB0000 size:00009000 access:R [D:\Facultate\_CURSURI_LABS\POO\POO-2024\L10\Release\Exceptii.exe]
addr:6C830000 size:0017B000 access:R [C:\Program Files\Bitdefender\Endpoint Security\atcuf\dlls_267797485796205114\atcuf32.dll]
addr:6C9B0000 size:000B4000 access:R [C:\Program Files\Bitdefender\Endpoint Security\bdhkm\dlls_267564230935842916\bdhkm32.dll]
addr:700C0000 size:0006D000 access:R [C:\Windows\SYSTEM32\MSVCP140.dll]
addr:72A10000 size:00015000 access:R [C:\Windows\SYSTEM32\VCRUNTIME140.dll]
addr:75650000 size:00110000 access:R [C:\Windows\System32\ucrtbase.dll]
addr:75C70000 size:001C8000 access:R [C:\Windows\System32\USER32.dll]
addr:75E40000 size:0001A000 access:R [C:\Windows\System32\win32u.dll]
addr:76390000 size:000ED000 access:R [C:\Windows\System32\gdi32full.dll]
addr:764F0000 size:00085000 access:R [C:\Windows\System32\msvcp_win.dll]
addr:76B90000 size:002AD000 access:R [C:\Windows\System32\KERNELBASE.dll]
addr:76F20000 size:000F0000 access:R [C:\Windows\System32\KERNEL32.DLL]
addr:770B0000 size:00022000 access:R [C:\Windows\System32\GDI32.dll]
addr:772D0000 size:00025000 access:R [C:\Windows\System32\IMM32.DLL]
addr:774F0000 size:001BA000 access:R [C:\Windows\SYSTEM32\ntdll.dll]

