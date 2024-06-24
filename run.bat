@echo off

g++ -o out.exe Main.cpp

if %ERRORLEVEL% neq 0 (
    echo Error: Fallo la compilacion.
    exit /b 1
)
out.exe

if %ERRORLEVEL% neq 0 (
    echo Error: Fallo la ejecucion.
    exit /b 1
)

exit /b 0
