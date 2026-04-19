#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>

#include "cpp-reference-benchmark/buffer.hpp"

using namespace cpp_ref_benchmark;

// BufferSumTest group
TEST(BufferSumTest, SumByValueWorks) {
    std::vector<int> data = {10, 20, 30};
    int expected = 60;

    EXPECT_EQ(sum_by_value(data), expected);
}

TEST(BufferSumTest, SumByConstRefWorks) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    int expected = 15;

    EXPECT_EQ(sum_by_const_ref(data), expected);
}

TEST(BufferSumTest, SumByRvalueWorks) {
    EXPECT_EQ(sum_by_rvalue(std::vector<int>{5, -5, 10}), 10);
}

// ElementAtTest group
TEST(ElementAtTest, ReturnsReferenceThatCanModify) {
    std::vector<int> data = {100, 200, 300};

    element_at(data, 1) = 999;

    EXPECT_EQ(data[1], 999);
}

TEST(ElementAtTest, ThrowsOnOutOfRange) {
    std::vector<int> data = {1, 2, 3};

    EXPECT_THROW({element_at(data, 5);}, std::out_of_range);
}

TEST(ElementAtTest, DoesNotThrowOnValidIndex) {
    std::vector<int> data = {1, 2, 3};

    EXPECT_NO_THROW({element_at(data, 2);});
}