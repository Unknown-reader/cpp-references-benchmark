cmake_minimum_required(VERSION 3.16)
project(cpp-reference-benchmark VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_TESTS "Enable building tests" ON)
option(ENABLE_BENCHMARKS "Enable building benchmakrs" ON)
option(ENABLE_EXAMPLES "Enable building examples" OFF)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-fsanitize=address -fsanitize=undefined)
    add_link_options(-fsanitize=address -fsanitize=undefined)
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)

if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(ENABLE_BENCHMARKS)
    add_subdirectory(benchmarks)
endif()

if(ENABLE_EXAMPLES)
    add_subdirectory(examples)
endif()