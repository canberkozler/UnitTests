cmake_minimum_required(VERSION 3.16)
project(UnitTestCatch2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
enable_testing()

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.12.0
)

FetchContent_MakeAvailable(Catch2)

add_subdirectory(src)
add_subdirectory(tests)