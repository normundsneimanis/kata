cmake_minimum_required(VERSION 4.0)
project(avl_tree)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_FLAGS -Wextra)
set(CMAKE_CXX_FLAGS -Wpedantic)
set(CMAKE_CXX_FLAGS -Werror)
set(CMAKE_CXX_FLAGS -Weffc++)
set(CMAKE_CXX_FLAGS -Wsign-conversion)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

add_executable(avl_tree main.cpp)
