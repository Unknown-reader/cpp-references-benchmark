#pragma once

#include <vector>
#include <cstddef>

namespace cpp_ref_bench {

/**
 * @brief Класс, имитирующий "дорогой" объект с большим объемом данных.
 *        При копировании выводит сообщение.
 */
class BigObject {
public:
    BigObject();

    BigObject(const BigObject& other);

    BigObject(BigObject&& other) = default;

    BigObject& operator=(const BigObject& other);

    long long sum() const;

    std::size_t size() const;

private:
    std::vector<int> data_;
};

} // namespace cpp_ref_bench