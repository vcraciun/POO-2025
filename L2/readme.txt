POO L2

1. Scrieti un proiect C, in care sa calculam aleatoriu, de 100 de ori:
   - aria dreptunghiului dat de l, L
   - aria patratului dat de l, 0
   - aria cercului dat de r, 0
   - suma numerelor a, b
   - produsul numerelor a, b
   - diferenta numerelor a, b
   - catul numerelor a, b
   - restul numerelor a, b
   - vom genera aleatoriu: 
     - functia de calcul
     - valorile
     - rezultatele calculelor trebuie sa fie de forma: FUNC(nr1, nr2) = nr3, iar acolo unde e doar un parametru, al 2-lea se ignora
       Ex: ARIA_CERC(10) = 61.8
       Ex: PRODUS(5,6) = 30        

1. Scrieti un proiect C format din 6 fisiere
   - 1 header: common.h care va contine prototipurile a 2 functii de calcul myfa()/myfb() (returneaza int, si iau 2 parametri int ca input)
   - 1 header: header1.h care va contine functia my_secret_func cu semnatura similara cu cele 2 de mai sus
   - 1 header: header2.h care va contine functia my_secret_func cu semnatura identica cu cea din header1.h
   - 1 cpp:    header1.cpp care va contine atat implementarea lui my_secret_func din header1.h cat si a functiei myfa
   - 1 cpp:    header2.cpp care va contine atat implementarea lui my_secret_func din header2.h cat si a functiei myfb
   - 1 cpp:    main.cpp
   
   functia my_secret_func din header1.cpp returneaza suma parametrilor
   functia my_secret_func din header2.cpp returneaza produsul parametrilor
   
   functia myfa implica my_secret_func din header1 intr-un calcul cu aparametrii acesteia
   functia myfb implica my_secret_func din header2 intr-un calcul cu aparametrii acesteia
   
   faceti in asa fel incat proiectul sa functioneaza iar functia my_secret_func sa fie aceeasi ca prototip si nume, in ambele module
   
2. scrieti o functie f_static() care sa declare o variabila statica x initializata cu valoarea 1633771873
   functia va returna un calcul in functie de aceasta valoare, dar nu va modifica valoarea variabilei
   scrieti o alta functie care sa fie apelata intre 2 apeluri consecutive ale lui f_static() si care va modifica valoarea variabilei

