cmake_minimum_required(VERSION 4.0)
project(ch05_constants_strings)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_FLAGS -Wextra)
set(CMAKE_CXX_FLAGS -Wpedantic)
set(CMAKE_CXX_FLAGS -Werror)
set(CMAKE_CXX_FLAGS -Weffc++)
set(CMAKE_CXX_FLAGS -Wsign-conversion)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

add_executable(ch05_constants_strings main.cpp)
add_executable(strings strings.cpp)

add_executable(ch05_exercises ch05_exercises.cpp)