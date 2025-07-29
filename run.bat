@echo off
setlocal enabledelayedexpansion

REM Root-ul proiectului
set "ROOT_DIR=%~dp0"

REM Folderul ce contine fisierele de compilare c++
set Compiler_DIR=%ROOT_DIR%\buildTool\MinGW\bin

REM Setez PATH temporar
set PATH=%Compiler_DIR%;%PATH%

REM Folderul de build
set BUILD_DIR=%ROOT_DIR%\buildTool\build

REM Creez folderul de build daca nu exista
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

set "EXE_NAME=Video_convertor.exe"
set "EXE_PATH=%BUILD_DIR%\%EXE_NAME%"

REM Navighez în build
cd /d "%BUILD_DIR%"

if exist "%EXE_PATH%" (
    echo [INFO] Executabilul exista deja. Rulez %EXE_NAME%...
    "%EXE_PATH%"
    goto :EOF
)

echo [Info] Generez fisierele de build cu CMake...
REM Rulez cmake pentru a genera makefiles (executabilele vor fi in build)
cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER="%Compiler_DIR%\gcc.exe"^
			    -DCMAKE_CXX_COMPILER="%Compiler_DIR%\g++.exe"^
			   ..\..


if errorlevel 1 (
    echo [ERORARE] CMake a esuat. Verifica CMakeLists.txt si directoarele.
    pause
    exit /b 1
)

echo [INFO] Compilez proiectul...
mingw32-make > build_log.txt 2>&1

if errorlevel 1 (
    echo [ERORARE] Compilarea a esuat. Verifica build_log.txt.
    pause
    exit /b 1
)

if exist "%EXE_PATH%" (
    echo [INFO] Build reusit. Rulez %EXE_NAME%...
    "%EXE_PATH%"
) else (
    echo [ERORARE] Executabilul nu a fost gasit dupa build!
)

pause
endlocal