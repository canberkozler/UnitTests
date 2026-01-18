add_executable(unit_tests_doctest
    tests.cpp
)

target_link_libraries(unit_tests_doctest
    PRIVATE
        my_lib
        doctest::doctest
)

add_test(
    NAME doctest_tests
    COMMAND unit_tests_doctest
)