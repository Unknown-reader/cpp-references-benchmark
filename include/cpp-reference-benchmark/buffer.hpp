#pragma once

#include <vector>
#include <stdexcept>
#include <string>

namespace cpp_ref_benchmark {

    int sum_by_value(std::vector<int> vec);
    int sum_by_const_ref(const std::vector<int>& vec);
    int sum_by_rvalue(std::vector<int>&& vec);

    int& element_at(std::vector<int>& vec, size_t index);
} // namespace cpp_ref_benchmark