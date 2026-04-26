#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "cpp-reference-benchmark/copy_vs_ref.hpp"
#include "cpp-reference-benchmark/BigObject.hpp"

using namespace cpp_ref_bench;

TEST(ValueVsRefTest, SumByValueCorrectness) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    int sum = 15;

    EXPECT_EQ(sum_by_copy(data), sum);
}

TEST(ValueVsRefTest, SumByConstRefCorrectness) {
    std::vector<int> data = {10, 20, 30};
    int sum = 60;

    EXPECT_EQ(sum_by_const_ref(data), sum);
}

TEST(ValueVsRefTest, ProcessStringCopyWorks) {
    std::string s = "My string for test\n";
    std::size_t len = s.size();

    EXPECT_EQ(process_string_copy(s), len);
}

TEST(ValueVsRefTest, ProcessStringConstRef) {
    std::string s = "My string for test\n";
    std::size_t len = s.size();

    EXPECT_EQ(process_string_copy(s), len);
}

TEST(ValueVsRefTest, ProcessBigObjectCopyWorks) {
    BigObject obj;
    long long sum_orig = obj.sum();
    long long sum_copy = process_big_object_copy(obj);

    EXPECT_EQ(sum_orig, sum_copy);
}

TEST(ValueVsRefTest, ProcessBigObjectConstRefWorks) {
    BigObject obj;
    long long sum_orig = obj.sum();
    long long sum_ref = process_big_object_const_ref(obj);

    EXPECT_EQ(sum_orig, sum_ref);
}