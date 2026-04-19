include(FetchContent)

FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG        v1.8.3
)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googlebenchmark)

set(BENCHMARK_SOURCES
    buffer_benchmark.cpp
    main_benchmark.cpp
)

add_executable(cpp-reference-benchmark_benchmarks ${BENCHMARK_SOURCES})

target_link_libraries(cpp-reference-benchmark_benchmarks
    PRIVATE
        cpp-reference-benchmark_lib
        benchmark::benchmark
)

set_target_properties(cpp-reference-benchmark_benchmarks PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)