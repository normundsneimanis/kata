cmake_minimum_required(VERSION 4.0)
project(ch01_basics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_FLAGS -Wextra)
set(CMAKE_CXX_FLAGS -Wpedantic)
set(CMAKE_CXX_FLAGS -Werror)
set(CMAKE_CXX_FLAGS -Weffc++)
set(CMAKE_CXX_FLAGS -Wsign-conversion)

add_executable(ch01_basics
        4_variable_init.cpp)
add_executable(4_double_number 4_double_number.cpp)

target_compile_options(ch01_basics PRIVATE -pedantic -pedantic-errors)
