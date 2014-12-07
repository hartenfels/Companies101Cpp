Implementation for [101 Companies](http://101companies.org/), see http://101companies.org/wiki/Contribution:cpp for details.

# Requirements
This application manages its build process using [CMake](http://www.cmake.org/). It also requires a C++11 capable compiler (e.g. GCC or Clang) and the [Boost](http://www.boost.org/) libraries installed.

# Unix

## Building
Open a terminal in the project directory and run the following commands:

    mkdir build
    cd build
    cmake ..
    make

This will find the required library and compiler information, and then build an executable.

## Testing
Just run `./companies101` after building.

# Windows
CMake comes with support for Visual Studio and the contribution is written in standard C++11, so in theory it should run on Windows with no modification. How exactly one builds anything in Visual Studio and what parts of the C++ standard its compiler actually supports has remained a mystery to me though, so I cannot provide any further instructions.

There is also MinGW and Cygwin to emulate a Unix environment, in which case you can follow the Unix instructions above.
