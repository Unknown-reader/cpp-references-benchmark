#include "cpp-reference-benchmark/value_vs_ref.hpp"
#include <numeric>

namespace cpp_ref_bench {

int sum_by_copy(std::vector<int> vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}

int sum_by_const_ref(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}

std::size_t process_string_copy(std::string s) {
    return s.size();
}

std::size_t process_string_const_ref(const std::string& s) {
    return s.size();
}

long long process_big_object_copy(BigObject obj) {
    return obj.sum();
}

long long process_big_object_const_ref(const BigObject& obj) {
    return obj.sum();
}

} // namespace cpp_ref_bench