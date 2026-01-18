cmake_minimum_required(VERSION 3.20)
project(gtest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(my_lib
    src/utils.cpp
)

target_include_directories(my_lib PUBLIC src)

enable_testing()
add_subdirectory(tests)