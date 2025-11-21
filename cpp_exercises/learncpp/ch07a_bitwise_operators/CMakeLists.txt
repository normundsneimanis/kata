cmake_minimum_required(VERSION 4.0)
project(ch07a_bitwise_operators)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_FLAGS -Wextra)
set(CMAKE_CXX_FLAGS -Wpedantic)
set(CMAKE_CXX_FLAGS -Werror)
set(CMAKE_CXX_FLAGS -Weffc++)
set(CMAKE_CXX_FLAGS -Wshadow)
set(CMAKE_CXX_FLAGS -Wsign-conversion)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

add_executable(ch07a_bitwise_operators main.cpp
        internal_external_linkage.cpp)
