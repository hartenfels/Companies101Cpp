cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)


set(sourceFiles
    src/Company.cpp
    src/Department.cpp
    src/Employee.cpp
    src/MutateVisitor.cpp
    src/Visitor.cpp
)


project("Contribution:Cpp")
add_executable(companies101 src/main.cpp ${sourceFiles})
include_directories(include)

set(myGnuFlags "-Wall -Wextra -pedantic -pedantic-errors -fexceptions")

if(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 ${myGnuFlags}")
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${myGnuFlags}")
endif()

