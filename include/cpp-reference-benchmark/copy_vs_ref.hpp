#pragma once

#include <vector>
#include <string>
#include "BigObject.hpp"

namespace cpp_ref_bench {

int sum_by_copy(std::vector<int> vec);
int sum_by_const_ref(const std::vector<int>& vec);

std::size_t process_string_copy(std::string s);
std::size_t process_string_const_ref(const std::string& s);

long long process_big_object_copy(BigObject obj);
long long process_big_object_const_ref(const BigObject& obj);

} // namespace cpp_ref_bench