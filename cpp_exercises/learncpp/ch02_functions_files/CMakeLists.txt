cmake_minimum_required(VERSION 4.0)
project(ch02_functions_files)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_FLAGS -Wextra)
set(CMAKE_CXX_FLAGS -Wpedantic)
set(CMAKE_CXX_FLAGS -Werror)
set(CMAKE_CXX_FLAGS -Weffc++)
set(CMAKE_CXX_FLAGS -Wsign-conversion)

add_executable(ch02_functions_files
        functions.cpp
        external_file.h
        external_file.cpp)

target_compile_options(ch02_functions_files PRIVATE -pedantic -pedantic-errors)
