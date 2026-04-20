#include "cpp-reference-benchmark/BigObject.hpp"
#include <iostream>
#include <numeric>

namespace cpp_ref_bench {

BigObject::BigObject() : data_(1'000'000, 0) {
    for (std::size_t i = 0; i < data_.size(); ++i) {
        data_[i] = static_cast<int>(i % 1000);
    }
}

BigObject::BigObject(const BigObject& other) : data_(other.data_) {
    std::cout << "[BigObject] Copy constructor called (expensive!)\n";
}

BigObject& BigObject::operator=(const BigObject& other) {
    if (this != &other) {
        data_ = other.data_;
        std::cout << "[BigObject] Copy assignment called (expensive!)\n";
    }

    return *this;
}

long long BigObject::sum() const {
    return std::accumulate(data_.begin(), data_.end(), 0LL);
}

std::size_t BigObject::size() const {
    return data_.size();
}

} // namespace cpp_ref_bench