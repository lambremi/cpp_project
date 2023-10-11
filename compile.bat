@echo off
chcp 65001

:start
cls
if not exist build mkdir build
cd build
if not exist temp mkdir temp

fc /b ..\CMakeLists.txt temp\CMakeLists.txt >nul 2>&1

if ERRORLEVEL 1 (
    echo [94m========== Création du Makefile ==========[0m
    cmake .. -G "MinGW Makefiles"
    if ERRORLEVEL 1 (
        echo [41mErreur de création du Makefile, veuillez voir le message CMake plus haut[0m
        del /q /s temp
        goto end
    )
    del *.exe
    copy ..\CMakeLists.txt temp\CMakeLists.txt >nul
)

echo.
echo [94m========== Compilation du Makefile ==========[0m
mingw32-make.exe

if NOT ERRORLEVEL 1 (
    for %%i in (*.exe) do (
        echo.
        echo [94m---------- Exécution de %%~i ----------[0m
        %%~i
        call :print_errlevel %%errorlevel%%
    )
) else (
    echo.
    echo [41mErreur de compilation, veuillez voir le message GCC plus haut[0m
)

:end
cd..
pause
goto start

:print_errlevel [errlevel]
	echo.
	echo [96mValeur de retour [97m%~1[0m
	goto :eof