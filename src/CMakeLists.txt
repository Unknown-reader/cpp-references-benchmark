set(LIB_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/value_vs_ref.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/return_ref.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/BigObject.cpp
)

add_library(cpp_ref_bench_lib STATIC ${LIB_SOURCES})

target_include_directories(cpp_ref_bench_lib
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(cpp_ref_bench_lib PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)