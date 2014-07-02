cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project("Contribution:Cpp")

find_package(Boost REQUIRED unit_test_framework)

set(sourceFiles
    src/Company.cpp
    src/Department.cpp
    src/Employee.cpp
    src/Equal.cpp
    src/MutateVisitor.cpp
    src/Operations.cpp
    src/Persistence.cpp
    src/Visitor.cpp
)

add_executable(companies101 src/test.cpp ${sourceFiles})
include_directories(include ${Boost_INCLUDE_DIRS})
target_link_libraries(companies101 ${Boost_LIBRARIES})

file(COPY sample.json DESTINATION ${CMAKE_BINARY_DIR})

set(myGnuFlags "-Wall -Wextra -pedantic -pedantic-errors -fexceptions")

if(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 ${myGnuFlags}")
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${myGnuFlags}")
endif()

