add_executable(unit_tests_catch2
    tests.cpp
)

target_link_libraries(unit_tests_catch2
    PRIVATE
        my_lib
        Catch2::Catch2WithMain
)

# for testing abort/fatal_error behavior
# add_executable(unit_tests_catch2
#     tests.cpp
#     $<TARGET_OBJECTS:my_lib_obj>
# )

# target_compile_definitions(unit_tests_catch2
#     PRIVATE
#         UNIT_TEST
# )

# target_link_libraries(unit_tests_catch2
#     PRIVATE
#         Catch2::Catch2WithMain
# )

include(CTest)
include(Catch)

catch_discover_tests(unit_tests_catch2)
