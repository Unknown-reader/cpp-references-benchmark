#include <benchmark/benchmark.h>
#include <vector>
#include <numeric>

#include "cpp-reference-benchmark/buffer.hpp"

using namespace cpp_ref_benchmark;

static std::vector<int> create_test_vector(size_t size) {
    std::vector<int> vec(size);
    std::iota(vec.begin(), vec.end(), 0);
    
    return vec;
}

static void BM_SumByValue(benchmark::State& state) {
    size_t vec_size = static_cast<size_t>(state.range(0));
    auto vec = create_test_vector(vec_size);

    for (auto _ : state) {
        int sum = sum_by_value(vec);
        benchmark::DoNotOptimize(sum);
    }

    state.SetBytesProcessed(static_cast<int64_t>(state.iterations()) * vec_size * sizeof(int));
}

BENCHMARK(BM_SumByValue)->Range(1024, 1'000'000'000'000);

static void BM_SumByConstRef(benchmark::State& state) {
    size_t vec_size = static_cast<size_t>(state.range(0));
    auto vec = create_test_vector(vec_size);

    for (auto _ : state) {
        int sum = sum_by_const_ref(vec);
        benchmark::DoNotOptimize(sum);
    }
    state.SetBytesProcessed(static_cast<int64_t>(state.iterations()) * vec_size * sizeof(int));
}
BENCHMARK(BM_SumByConstRef)->Range(1024, 1'000'000'000'000);

static void BM_SumByRvalue(benchmark::State& state) {
    size_t vec_size = static_cast<size_t>(state.range(0));
    
    for (auto _ : state) {
        // Создаём временный вектор прямо в вызове — это rvalue.
        // sum_by_rvalue примет его по rvalue-ссылке, избегая копирования.
        int sum = sum_by_rvalue(create_test_vector(vec_size));
        benchmark::DoNotOptimize(sum);
    }
    state.SetBytesProcessed(static_cast<int64_t>(state.iterations()) * vec_size * sizeof(int));
}
BENCHMARK(BM_SumByRvalue)->Range(1024, 1'000'000'000'000);