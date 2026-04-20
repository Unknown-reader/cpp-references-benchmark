#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <stdexcept>
#include "cpp-reference-benchmark/return_ref.hpp"

using namespace cpp_ref_bench;

TEST(ReturnRefTest, ElementAtReturnsReference) {
    std::vector<int> vec = {10, 20, 30};
    element_at(vec, 1) = 99;

    EXPECT_EQ(vec[1], 99);
}

TEST(ReturnRefTest, ElementAtThrowsOnInvalidIndex) {
    std::vector<int> vec = {1, 2, 3};

    EXPECT_THROW(element_at(vec, 5), std::out_of_range);
    EXPECT_THROW(element_at(vec, vec.size()), std::out_of_range);
    EXPECT_NO_THROW(element_at(vec, 0));
}

TEST(ReturnRefTest, GetNameReturnsConstReference) {
    Person girlfriend{"Sasha", 21};
    const std::string& name_ref = get_name(girlfriend);

    EXPECT_EQ(name_ref, "Sasha");

    girlfriend.name = "Alexandra";

    EXPECT_EQ(name_ref, "Alexandra");
}