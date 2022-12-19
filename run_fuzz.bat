:again
mkdir corpus\corpus0 2> nul
mkdir corpus\corpus1 2> nul
mkdir corpus\corpus2 2> nul
mkdir corpus\corpus3 2> nul
mkdir corpus\corpus4 2> nul
mkdir corpus\corpus5 2> nul
mkdir corpus\corpus6 2> nul
mkdir corpus\corpus7 2> nul
mkdir corpus\corpus8 2> nul
mkdir corpus\corpus9 2> nul
x64\Debug\mk_parse_int.exe -max_len=32 -runs=10000000 corpus\corpus9
del /q corpus\corpus0\*.*
rmdir corpus\corpus0
cd corpus
ren corpus1 corpus0
ren corpus2 corpus1
ren corpus3 corpus2
ren corpus4 corpus3
ren corpus5 corpus4
ren corpus6 corpus5
ren corpus7 corpus6
ren corpus8 corpus7
mkdir corpus8
cd ..
x64\Debug\mk_parse_int.exe -merge=1 corpus\corpus8 corpus\corpus9
del /q corpus\corpus9\*.*
copy corpus\corpus8\*.* corpus\corpus9
goto again
