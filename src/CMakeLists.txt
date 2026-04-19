set(LIB_SOURCES
    buffer.cpp
    json_utils.cpp
)

add_library(cpp-reference-benchmark_lib STATIC ${LIB_SOURCES})

target_include_directories(cpp-reference-benchmark_lib
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(cpp-reference-benchmark_lib PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)