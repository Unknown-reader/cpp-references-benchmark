#include <benchmark/benchmark.h>
#include <vector>
#include <string>
#include <numeric>
#include <cstddef>
#include <optional>
#include "cpp-reference-benchmark/copy_vs_ref.hpp"
#include "cpp-reference-benchmark/BigObject.hpp"

using namespace cpp_ref_bench;


static std::vector<int> create_vector(std::size_t size) {
    std::vector<int> v(size);
    std::iota(v.begin(), v.end(), 0);

    return v;
}

static std::string create_string(std::size_t lenght) {
    return std::string(lenght, 'x');
}


// ---------- Бенчмарки для std::vector<int> ----------
class SumVectorFixture : public benchmark::Fixture {
    protected:
        std::vector<int> input_vector;

        void SetUp(const ::benchmark::State& state) override {
            input_vector = create_vector(state.range(0));
        }
};

BENCHMARK_DEFINE_F(SumVectorFixture, BM_SumVectorPassedByCopy)
(benchmark::State& state) {
    for (auto _ : state) {
        auto sum = sum_by_copy(input_vector);
        benchmark::DoNotOptimize(sum);
    }
}

BENCHMARK_DEFINE_F(SumVectorFixture, BM_SumVectorPassedByConstRef)
(benchmark::State& state) {
    for (auto _ : state) {
        auto sum = sum_by_const_ref(input_vector);
        benchmark::DoNotOptimize(sum);
    }
}

BENCHMARK_REGISTER_F(SumVectorFixture, BM_SumVectorPassedByCopy)
    ->Arg(1'000)
    ->Arg(1'000'000);

BENCHMARK_REGISTER_F(SumVectorFixture, BM_SumVectorPassedByConstRef)
    ->Arg(1'000)
    ->Arg(1'000'000);


// ---------- Бенчмарки для std::string (sso) ----------
class ShortStrProcessFixture : public benchmark::Fixture {
    protected:
        std::string short_str;

        void SetUp(const benchmark::State& state) override {
            std::string str;
            std::size_t short_string_capacity = (str.capacity() > 0) ? str.capacity() : 15;
            
            short_str = create_string(short_string_capacity);
        }
};

BENCHMARK_DEFINE_F(ShortStrProcessFixture, BM_ProcessShortStrPassedByCopy)
(benchmark::State& state) {
    for (auto _ : state) {
        auto len = process_string_copy(short_str);
        benchmark::DoNotOptimize(len);
    }
}

BENCHMARK_DEFINE_F(ShortStrProcessFixture, BM_ProcessShortStrPassedByConstRef)
(benchmark::State& state) {
    for (auto _ : state) {
        auto len = process_string_const_ref(short_str);
        benchmark::DoNotOptimize(len);
    }
}

BENCHMARK_REGISTER_F(ShortStrProcessFixture, BM_ProcessShortStrPassedByCopy);

BENCHMARK_REGISTER_F(ShortStrProcessFixture, BM_ProcessShortStrPassedByConstRef);


// ---------- Бенчмарки для std::string (long) ----------
class LongStrProcessFixture : public benchmark::Fixture {
    protected:
        std::string long_str;

        void SetUp(const benchmark::State& state) override {
            long_str = create_string(100'000);
        }
};

BENCHMARK_DEFINE_F(LongStrProcessFixture, BM_ProcessLongStrPassedByCopy)
(benchmark::State& state) {
    for (auto _ : state) {
        auto len = process_string_copy(long_str);
        benchmark::DoNotOptimize(len);
    }
}

BENCHMARK_DEFINE_F(LongStrProcessFixture, BM_ProcessLongStrPassedByConstRef)
(benchmark::State& state) {
    for (auto _ : state) {
        auto len = process_string_const_ref(long_str);
        benchmark::DoNotOptimize(len);
    }
}

BENCHMARK_REGISTER_F(LongStrProcessFixture, BM_ProcessLongStrPassedByCopy);

BENCHMARK_REGISTER_F(LongStrProcessFixture, BM_ProcessLongStrPassedByConstRef);


// ---------- Бенчмарки для BigObject ----------
class BigObjectProcessFixture : public benchmark::Fixture {
    protected:
        std::optional<BigObject> obj;

        void SetUp(const benchmark::State& state) override {
            obj.emplace();
        }
};

BENCHMARK_DEFINE_F(BigObjectProcessFixture, BM_ProcessBigObjectPassedByCopy)
(benchmark::State& state) {
    for (auto _ : state) {
        long long sum = process_big_object_copy(obj.value());
        benchmark::DoNotOptimize(sum);
    }
}

BENCHMARK_DEFINE_F(BigObjectProcessFixture, BM_ProcessBigObjectPassedByConstRef)
(benchmark::State& state) {
    for (auto _ : state) {
        long long sum = process_big_object_const_ref(obj.value());
        benchmark::DoNotOptimize(sum);
    }
}

BENCHMARK_REGISTER_F(BigObjectProcessFixture, BM_ProcessBigObjectPassedByCopy);

BENCHMARK_REGISTER_F(BigObjectProcessFixture, BM_ProcessBigObjectPassedByConstRef);