#include "cpp-reference-benchmark/buffer.hpp"
#include <numeric>
#include <stdexcept>
#include <cstddef>

namespace cpp_ref_benchmark {

int sum_by_value(std::vector<int> vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}

int sum_by_const_ref(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}

int sum_by_rvalue(std::vector<int>&& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}

int& element_at(std::vector<int>&  vec, std::size_t index){
    if (index >= vec.size()) {
        throw std::out_of_range("elelment_at: index out of range");
    }

    return vec[index];
}

} // namespace cpp_ref_benchmark