include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

add_executable(unit_tests
    test.cpp
)

target_link_libraries(unit_tests
    PRIVATE
        my_lib
        gtest
        gtest_main
)

add_test(NAME unit_tests COMMAND unit_tests)
