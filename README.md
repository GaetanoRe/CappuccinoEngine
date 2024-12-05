# CappuccinoEngine
Open-Source Modular Game Engine made to be able to run on all platforms from it's conception to when it fully releases. It is a base to help game developers have complete freedom with whatever game they want to make. The goal of this project is to make building this engine as easy and as streamlined as possible for anyone looking to create their own engine, or to be an engine that is completey modular and easy to understand for others. Though this engine will come with improvements down the line, it is open source so if you have a better idea on how this engine can improve, you have full freedom to do what you want on your own fork.

## Using the Engine
Just download one of the releases on the github and run the exe, there should be no issues unless you downloaded it for the wrong system.

## Building the Engine
### Tools you will need (This list is for ALL Systems):
- Git
- Vcpkg
- CMake
- Any type of code editor or IDE designed for C++ or C (make sure you use cmake so that it integrates with vcpkg)

### Tools you will need (System Specific):
#### For Windows:
- Visual Studio 2022 with the C++ Desktop Environment Package (Disclaimer: If you would like to use Visual studio code, that is fine, but you must install this for the native windows C++ compiler and C compiler)
#### For Mac/Linux
- Ninja


### Setup
1) Clone this repository into your designated area for projects.
2) Go to the setup-files directory and there should be two folders. These folders contain scripts that run on the designated operating systems for vcpkg to download and build the libraries for you, minimizing setup. (Disclaimer: If vcpkg is not in any PATH environment variable, it will not work. For Linux/Mac users, you should only need to have vcpkg cloned in your home directory)
3) Once the libraries are fully downloaded, just go to your command prompt, type: vcpkg integrate install, and vcpkg will automatically configure your build system to work with the libraries it just downloaded

### Setup for VSCode
1) You will need to download all extensions for CMake and C/C++
2) Go to your settings.json and add this to the list of settings:
#### For Windows:
```
}
"cmake.configureArgs": [
    "-DCMAKE_TOOLCHAIN_FILE=${env:VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" 
    ],
    "cmake.generator": "Visual Studio 17 2022"
{
```
#### For Mac/Linux:
```
}
"cmake.configureArgs": [
    "-DCMAKE_TOOLCHAIN_FILE=${env:VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" 
    ],
    "cmake.generator": "Ninja"
{
```

### When Using Cmake Manually
Make sure you type your commands to build the project in the command line as shown:
#### For Windows:
```
cmake -S <source_dir> -B <build_dir> -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%/scripts/buildsystems/vcpkg.cmake
```

#### For Mac/Linux:
```
cmake -S <source_dir> -B <build_dir> -G "Ninja" -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
```

