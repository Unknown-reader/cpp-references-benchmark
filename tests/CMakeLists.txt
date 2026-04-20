include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

set(TEST_SOURCES
    test_value_vs_ref.cpp
    test_return_ref.cpp
)

add_executable(run_tests ${TEST_SOURCES})

target_link_libraries(run_tests
    PRIVATE
        cpp_ref_bench_lib
        gtest_main
)

set_target_properties(run_tests PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

include(GoogleTest)
gtest_discover_tests(run_tests)