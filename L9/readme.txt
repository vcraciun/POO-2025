clasa FileProcessor scaneaza folderul files si coontruieste o colectie de date cu cele mai frecvente n cuvinte
Colectia trebuie sa fie organizata astfel incat sa putem afisa pentru setul de date (19 fisere), urmatorul output:
De exemplu, in fisierul smp_text.ini, cele mai frecvente 5 cuvinte sunt (cuvant:frecventa): {(and:92), (of:96), (the:263), (to:110), (you:91)}
un cuvant este o insiruire de caractere [a-zA-Z], orice caracter special este considerat element de split
procesarea caracterelor este case-insensitive

.cfg :
        _c_ast.cfg : {(a:23), (name:31), (of:17), (the:17), (type:21)}
        autom4te.cfg : {(ac:33), (am:29), (language:24), (m:27), (preselect:65)}
.ini :
        browscap.ini : {(mozilla:253), (netscape:182), (parent:252), (platform:244), (win:258)}
        smp_text.ini : {(and:92), (of:96), (the:263), (to:110), (you:91)}
.json :
        v11_CL.json : {(comment:141), (flags:141), (name:145), (switch:141), (value:141)}
        v143_CL.json : {(comment:197), (flags:197), (name:204), (switch:197), (value:197)}
.log :
        MSTeams_2022-12-15_01-28-19.00.log : {(a:151), (scenario:531), (start:225), (success:250), (x:281)}
        john.log : {(accepted:5385), (as:5313), (az:4059), (length:3944), (rule:5441)}
        remotescan37312.log : {(bd:1223), (m:1160), (oct:1207), (scan:1160), (scanclient:1207)}
.md :
        README1.md : {(a:44), (file:111), (module:56), (sharedir:45), (the:93)}
        README2.md : {(db:29), (man:43), (of:45), (the:93), (to:58)}
        README3.md : {(a:104), (in:63), (of:70), (the:145), (to:81)}
.rtf :
        Eula.rtf : {(af:1485), (f:1087), (fcs:1182), (ltrch:591), (rtlch:591)}
.txt :
        guile-procedures.txt : {(a:1062), (is:1161), (procedure:1284), (scheme:1159), (the:2731)}
        man-db-manual.txt : {(a:197), (m:506), (manual:170), (the:440), (to:199)}
        xdmcp.txt : {(a:154), (display:166), (of:158), (the:435), (to:204)}
.xml :
        Microsoft.XboxGamingOverlay_7.124.3191.0_x64__8wekyb3d8bbwe.xml : {(activatableclass:103), (activatableclassid:100), (both:100), (canvas:100), (microsoft:148)}
        energy-report-2024-04-16.xml : {(a:1252), (detail:1142), (f:1180), (name:1336), (value:1142)}
        library.xml : {(device:612), (function:1422), (listitem:530), (para:1206), (the:1551)}
