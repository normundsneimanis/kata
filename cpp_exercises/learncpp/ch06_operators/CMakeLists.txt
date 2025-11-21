cmake_minimum_required(VERSION 4.0)
project(ch06_operators)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_FLAGS -Wextra)
set(CMAKE_CXX_FLAGS -Wpedantic)
set(CMAKE_CXX_FLAGS -Werror)
set(CMAKE_CXX_FLAGS -Weffc++)
set(CMAKE_CXX_FLAGS -Wsign-conversion)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

add_executable(ch06_operators main.cpp
        ch06_quiz.cpp)
add_executable(compare_double compare_double.cpp)

add_executable(ch06_quiz ch06_quiz.cpp)