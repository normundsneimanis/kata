cmake_minimum_required(VERSION 4.0)
project(ch00_intro)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_FLAGS -Wextra)
set(CMAKE_CXX_FLAGS -Wpedantic)
set(CMAKE_CXX_FLAGS -Werror)
set(CMAKE_CXX_FLAGS -Weffc++)
set(CMAKE_CXX_FLAGS -Wsign-conversion)

add_executable(ch00_intro main.cpp)
add_executable(print_cpp_compiler_standard print_cpp_compiler_standard.cpp)

target_compile_options(ch00_intro PRIVATE -pedantic -pedantic-errors)
