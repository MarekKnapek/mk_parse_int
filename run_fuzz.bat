if "%~1"=="x86d" goto x86d
if "%~1"=="x86r" goto x86r
if "%~1"=="x64d" goto x64d
if "%~1"=="x64r" goto x64r
if "%~1"=="xcns" goto xcns
if "%~1"=="xcnsx86d" goto xcnsx86d
if "%~1"=="xcnsx86r" goto xcnsx86r
if "%~1"=="xcnsx64d" goto xcnsx64d
if "%~1"=="xcnsx64r" goto xcnsx64r
if "%~1"=="" goto xstart
goto xend
:xstart
mkdir "%~dp0corpus\corpus0" 2> nul
mkdir "%~dp0corpus\corpus1" 2> nul
mkdir "%~dp0corpus\corpus2" 2> nul
mkdir "%~dp0corpus\corpus3" 2> nul
mkdir "%~dp0corpus\corpus4" 2> nul
mkdir "%~dp0corpus\corpus5" 2> nul
mkdir "%~dp0corpus\corpus6" 2> nul
mkdir "%~dp0corpus\corpus7" 2> nul
mkdir "%~dp0corpus\corpus8" 2> nul
mkdir "%~dp0corpus\corpus9" 2> nul
mkdir "%~dp0corpus\corpus_x86d" 2> nul
mkdir "%~dp0corpus\corpus_x86r" 2> nul
mkdir "%~dp0corpus\corpus_x64d" 2> nul
mkdir "%~dp0corpus\corpus_x64r" 2> nul
:again
%comspec% /c ""%~f0" "x86d""
%comspec% /c ""%~f0" "x86r""
%comspec% /c ""%~f0" "x64d""
%comspec% /c ""%~f0" "x64r""
%comspec% /c ""%~f0" "xcns""
goto again
:x86d
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat"
"%~dp0Debug\mk_parse_int.exe" "-max_len=32" "-runs=10000000" "%~dp0corpus\corpus_x86d"
goto xend
:x86r
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat"
"%~dp0Release\mk_parse_int.exe" "-max_len=32" "-runs=10000000" "%~dp0corpus\corpus_x86r"
goto xend
:x64d
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
"%~dp0x64\Debug\mk_parse_int.exe" "-max_len=32" "-runs=10000000" "%~dp0corpus\corpus_x64d"
goto xend
:x64r
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
"%~dp0x64\Release\mk_parse_int.exe" "-max_len=32" "-runs=10000000" "%~dp0corpus\corpus_x64r"
goto xend
:xcns
del /q "%~dp0corpus\corpus0\*.*"
rmdir "%~dp0corpus\corpus0"
pushd "%~dp0"
cd "corpus"
ren "corpus1" "corpus0"
ren "corpus2" "corpus1"
ren "corpus3" "corpus2"
ren "corpus4" "corpus3"
ren "corpus5" "corpus4"
ren "corpus6" "corpus5"
ren "corpus7" "corpus6"
ren "corpus8" "corpus7"
ren "corpus9" "corpus8"
mkdir "corpus9"
cd ..
popd
%comspec% /c ""%~f0" "xcnsx86d""
%comspec% /c ""%~f0" "xcnsx86r""
%comspec% /c ""%~f0" "xcnsx64d""
%comspec% /c ""%~f0" "xcnsx64r""
del /q "%~dp0corpus\corpus_x86d\*.*"
del /q "%~dp0corpus\corpus_x86r\*.*"
del /q "%~dp0corpus\corpus_x64d\*.*"
del /q "%~dp0corpus\corpus_x64r\*.*"
copy "%~dp0corpus\corpus9\*.*" "%~dp0corpus\corpus_x86d"
copy "%~dp0corpus\corpus9\*.*" "%~dp0corpus\corpus_x86r"
copy "%~dp0corpus\corpus9\*.*" "%~dp0corpus\corpus_x64d"
copy "%~dp0corpus\corpus9\*.*" "%~dp0corpus\corpus_x64r"
goto xend
:xcnsx86d
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat"
"%~dp0Debug\mk_parse_int.exe" -merge=1 "%~dp0corpus\corpus9" "%~dp0corpus\corpus_x86d"
goto xend
:xcnsx86r
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat"
"%~dp0Release\mk_parse_int.exe" -merge=1 "%~dp0corpus\corpus9" "%~dp0corpus\corpus_x86r"
goto xend
:xcnsx64d
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
"%~dp0x64\Debug\mk_parse_int.exe" -merge=1 "%~dp0corpus\corpus9" "%~dp0corpus\corpus_x64d"
goto xend
:xcnsx64r
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
"%~dp0x64\Release\mk_parse_int.exe" -merge=1 "%~dp0corpus\corpus9" "%~dp0corpus\corpus_x64r"
goto xend
:xend
