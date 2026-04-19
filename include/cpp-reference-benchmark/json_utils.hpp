#pragma once

#include <string>
#include <string_view>
#include <optional>

namespace cpp_ref_benchmark {

    std::optional<std::string> get_field_copy(const std::string& json);

    std::optional<std::string_view> get_field_view(std::string_view json);
} // namespace cpp_ref_benchmark