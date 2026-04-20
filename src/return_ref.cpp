#include "cpp-reference-benchmark/return_ref.hpp"

namespace cpp_ref_bench {

int& element_at(std::vector<int>& vec, std::size_t index) {
    if (index >= vec.size()) {
        throw std::out_of_range("element_at: index out of range");
    }
    return vec[index];
}

const std::string& get_name(const Person& p) {
    return p.name;
}

const int& dangling_reference_example() {
    int local_var = 42;
    return local_var;
}

} // namespace cpp_ref_bench