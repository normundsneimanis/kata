cmake_minimum_required(VERSION 4.0)
project(ch04_types)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_FLAGS -Wextra)
set(CMAKE_CXX_FLAGS -Wpedantic)
set(CMAKE_CXX_FLAGS -Werror)
set(CMAKE_CXX_FLAGS -Weffc++)
set(CMAKE_CXX_FLAGS -Wsign-conversion)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

add_executable(ch04_types main.cpp
        ch04_exercises.cpp)
target_compile_options(ch04_types PRIVATE -pedantic -pedantic-errors)

add_executable(cin_boolean cin_boolean.cpp)

add_executable(ch04_exercises ch04_exercises.cpp)