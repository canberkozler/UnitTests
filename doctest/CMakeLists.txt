cmake_minimum_required(VERSION 3.20)
project(doctestTesting LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
enable_testing()

FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/doctest/doctest.git
    GIT_TAG v2.4.12
)

FetchContent_MakeAvailable(doctest)

add_subdirectory(src)
add_subdirectory(tests)