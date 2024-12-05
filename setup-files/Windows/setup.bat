@echo off

:: Path to the libraries file
set LIBRARIES_FILE=..\..\libraries.txt

:: Check if libraries file exists
if not exist %LIBRARIES_FILE% (
    echo libraries.txt not found in the project root. Please create it and list the libraries to install.
    exit /b 1
)

:: Check if vcpkg is in the PATH
where vcpkg >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo vcpkg not found in PATH. Please add it to your PATH or specify its location.
    exit /b 1
)

echo vcpkg found in PATH.

:: Install libraries from file
for /f "tokens=*" %%L in (%LIBRARIES_FILE%) do (
    echo Installing %%L...
    vcpkg install %%L --triplet x64-windows || exit /b 1
)

echo All libraries installed successfully!
pause
