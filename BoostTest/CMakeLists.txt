cmake_minimum_required(VERSION 3.16)
project(UnitTestBoost LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

cmake_policy(SET CMP0144 NEW)
cmake_policy(SET CMP0167 NEW)

set(BOOST_ROOT "C:/boost_1_90_0")
set(BOOST_LIBRARYDIR "C:/boost_1_90_0/stage/lib")

find_package(Boost 1.90 REQUIRED COMPONENTS unit_test_framework)

add_subdirectory(src)
add_subdirectory(tests)