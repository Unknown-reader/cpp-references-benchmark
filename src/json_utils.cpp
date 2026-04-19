#include "cpp-reference-benchmark/json_utils.hpp"
#include <cstddef>

namespace cpp_ref_benchmark {

namespace {

    std::pair<std::size_t, std::size_t> find_name_value(std::string_view json) {
        const std::string_view key =  "\"name\":\"";

        auto pos = json.find(key);
        if (pos == std::string_view::npos) {
            return {std::string_view::npos, 0};
        }

        pos += key.size();

        auto end_pos = json.find('"', pos);
        if (end_pos == std::string_view::npos) {
            return {std::string_view::npos, 0};
        }

        return {pos, end_pos - pos};
    }

}

std::optional<std::string> get_field_copy(const std::string& json) {
    std::string_view view(json);

    auto [start, len] = find_name_value(view);
    if (start == std::string_view::npos) {
        return std::nullopt;
    }

    return std::string(view.substr(start, len));
}

std::optional<std::string_view> get_field_view(std::string_view json) {
    auto [start, len] = find_name_value(json);
    if (start == std::string_view::npos) {
        return std::nullopt;
    }

    return json.substr(start, len);
}

} // namespace cpp_ref_benchmark