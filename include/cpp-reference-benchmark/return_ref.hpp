#pragma once

#include <vector>
#include <string>
#include <stdexcept>

namespace cpp_ref_bench {

struct Person {
    std::string name;
    int age;
};

// Возвращает ссылку на элемент вектора с проверкой границ
int& element_at(std::vector<int>& vec, std::size_t index);

// Возвращает константную ссылку на имя человека
const std::string& get_name(const Person& p);

} // namespace cpp_ref_bench