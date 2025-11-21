cmake_minimum_required(VERSION 4.0)
project(ch03_debugging)
include(FetchContent)

FetchContent_Declare(
        plog
        GIT_REPOSITORY https://github.com/SergiusTheBest/plog
        GIT_TAG        1.1.10
        GIT_SHALLOW    true
        # Use PATCH_COMMAND to execute sed directly
        PATCH_COMMAND
        /usr/bin/sed -i "s/cmake_minimum_required(VERSION [0-9]\\.[0-9].*)/cmake_minimum_required(VERSION 3.5)/g" CMakeLists.txt
)
FetchContent_MakeAvailable(plog) # Downloads and adds plog to your CMake project

set(CMAKE_CXX_STANDARD 11)

add_executable(ch03_debugging main.cpp)
target_link_libraries(ch03_debugging plog::plog) # Links and sets include path
