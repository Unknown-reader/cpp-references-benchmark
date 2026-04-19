#include <gtest/gtest.h>
#include <optional>
#include <string>
#include <string_view>

#include "cpp-reference-benchmark/json_utils.hpp"

using namespace cpp_ref_benchmark;

TEST(JsonUtilsTest, GetFieldCopyValidJson) {
    std::string json = R"({"name":"John", "age":30})";

    auto result = get_field_copy(json);

    ASSERT_TRUE(result.has_value());

    EXPECT_EQ(*result, "John");
}

TEST(JsonUtilsTest, GetFieldCopyMissingField) {
    std::string json = R"("age":30)";

    auto result = get_field_copy(json);

    EXPECT_FALSE(result.has_value());
}

TEST(JsonUtilsTest, GetFieldViewValidJson) {
    std::string json_str = R"({"name":"Alice", "city":"Paris"})";
    std::string_view json_view(json_str);

    auto result = get_field_view(json_view);

    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(*result, "Alice");
}

TEST(JsonUtilsTest, GetFieldViewMissingField) {
    std::string json_str = R"({"not_name":"Bob"})";
    std::string_view json_view(json_str);

    auto result = get_field_view(json_view);

    EXPECT_FALSE(result.has_value());
}