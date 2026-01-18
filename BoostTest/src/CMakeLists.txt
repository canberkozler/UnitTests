add_library(my_lib
    utils.cpp
)

target_include_directories(my_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)