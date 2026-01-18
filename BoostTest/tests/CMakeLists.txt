add_executable(unit_tests_boost
    test_utils.cpp
    test_dcalculator.cpp
)

target_link_libraries(unit_tests_boost
    PRIVATE
        my_lib
        Boost::unit_test_framework
)

target_include_directories(unit_tests_boost
    PRIVATE ${PROJECT_SOURCE_DIR}/src
)

add_test(NAME boost_tests COMMAND unit_tests_boost)