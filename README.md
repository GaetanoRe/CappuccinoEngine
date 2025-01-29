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

#### Disclaimer: If vcpkg is not working out for you on your Linux distribution or on your Mac, you may result to utilizing your built in package manager for the following libraries. The libraries needed are listed in the libraries.txt file.

### Tools you will need (System Specific):
#### For Windows:
- MSYS2
- MinGW-w64 toolchain (provided with MSYS2)
- Ninja (for faster builds, also provided with MSYS2)
- Make (provided with MSYS2)
DISCLAIMER: You may just utilize Visual Studio 2022 Community Edition with the C++ Destop Development Package included. However, this is a proprietary Compiler, so to keep things open source, MSYS2 is preferred.

#### For Linux
- Ninja
- libxinerama
- libxcursor
- xorg
- libglu1-mesa
- pkg-config
- autoconf
- libtool

#### For Mac
- Ninja 
- pkg-config 
- autoconf 
- libtool
- XCode Command Line Tools

### MSYS2 Environment Setup (Windows Only)
1) Install MSYS2 and follow the instructions on the website up to step 5: https://www.msys2.org/
2) Close the UCRT64 window and search for your msys2 folder that you set your installation to
3) Run the "msys2.exe" executable
4) Run these commands:
```
$ pacman -Syu
$ pacman -S --needed base-devel mingw-w64-x86_64-toolchain mingw-w64-x86_64-cmake mingw-w64-x86_64-ninja
```
5) Once this is done installing, go to your PATH variable and add the the following directory within your msys2 folder:
```
/mingw64/bin/
```

You are all set up!!!

### VCPKG Enviornment Setup
#### Windows:
1) Clone the official vcpkg repository anywhere in your files : https://github.com/microsoft/vcpkg.git
2) Double click the bootstrap-vcpkg.bat file and it will download the executable
3) Go to the Start menu and look for "Edit Environment Variables"
4) Go to the PATH variable and add the location of the vcpkg repo to the list of PATH variables
5) Create a System Environment variable named "VCPKG_ROOT"
6) Open the command prompt and type "vcpkg" if a bunch of options came up, it should be installed properly.

#### Linux/Mac:
1) Clone the github repository into the ~/ directory using this link: https://github.com/microsoft/vcpkg.git
2) Go to the vcpkg directory and do this command:
```
sudo chmod +x bootstrap-vcpkg.sh
```
3) Run the shell script with this command:
```
./bootstrap-vcpkg.sh
```
4) Change your directory back to the home directory (~)
5) Use VIM to edit your OS' shell configuration file according to what type of shell your OS uses (Linux users google for the name of the config file for their distribution. For Mac users, the name should always be .zshrc). 
```
vim <insert name of shell configuration file>
```
6) Then type this anywhere in the file:
```
export PATH="$HOME/vcpkg:$PATH"
```
7) Next, reload the shell configuration:
```
source ~/<insert name of shell configuration file>
```
8) Now, test the installation. You should get a result from just typing vcpkg

##### (For Linux)
9) Install the following packages using your distro's package manager(each of the packages might have different names depending on the distro. Make sure you also have cmake installed and any build-essential or packages like it):
- ninja
- libxinerama
- libxcursor
- xorg
- libglu1-mesa
- pkg-config
- autoconf
- libtool

##### (For Mac)
9) Install the following packages using Homebrew(Make sure you have installed the XCode Command Line tools and CMake):
- ninja  
- pkg-config 
- autoconf 
- libtool



### Setup (For after VCPKG Environment Setup)
1) Clone this repository into your designated area for projects.
2) Go to the setup-files directory and there should be two folders. These folders contain scripts that run on the designated operating systems for vcpkg to download and build the libraries for you, minimizing setup. (Disclaimer: If vcpkg is not in any PATH environment variable, it will not work. For Linux/Mac users, you should only need to have vcpkg cloned in your home directory)
3) Once the libraries are fully downloaded, just go to your command prompt, type: vcpkg integrate install, and vcpkg will automatically configure your build system to work with the libraries it just downloaded

### Setup for VSCode
1) You will need to download all extensions for CMake and C/C++
2) Go to your settings.json and add this to the list of settings:
#### For Windows:
```
"C_Cpp_Runner.cCompilerPath": "g++",
"C_Cpp_Runner.cppCompilerPath": "g++",
"C_Cpp.default.compilerPath": "g++",
{
"cmake.configureArgs": [
    "-DCMAKE_TOOLCHAIN_FILE=${env:VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" 
    ],
    "cmake.generator": "Ninja"
}
```

(You will have to force VSCode for Windows to specify g++ as the prefered compiler since MVSC (the default windows compiler) is not open source.)
#### For Mac/Linux:
```
{
"cmake.configureArgs": [
    "-DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake" 
    ],
    "cmake.generator": "Ninja"
}
```

### When Using Cmake Manually
Make sure you type your commands to build the project in the command line as shown:
```
cmake -S <source_dir> -B <build_dir> -G "Ninja" -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
```

### Visual Studio Community Edition
Visual Studio itself should require very minimal setup, just find the project in the directory you cloned it into. (However, the Visual Studio Code Environment is reccomended to keep the binaries open source)

