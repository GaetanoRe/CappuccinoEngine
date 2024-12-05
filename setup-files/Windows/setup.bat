@echo off

:: Check if vcpkg is in the PATH
where vcpkg >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo vcpkg not found in PATH. Please add it to your PATH or specify its location.
    exit /b 1
)

echo vcpkg found in PATH.

:: List of libraries to install
set LIBRARIES=glfw3 glew soil freetype glm bullet3 openal-soft

:: Install libraries
for %%L in (%LIBRARIES%) do (
    echo Installing %%L...
    vcpkg install %%L --triplet x64-windows || exit /b 1
)

echo All libraries installed successfully!
pause