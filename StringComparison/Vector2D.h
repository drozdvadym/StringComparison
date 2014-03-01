#pragma once

#include <vector>

/*
 * Declarations
 */

template <typename _T>
class Vector2D
{
public:
    Vector2D(size_t s1 = 1, size_t s2 = 1);
    _T & elem(size_t idx1, size_t idx2);
    void show();
private:
    int getIdx(size_t idx1, size_t idx2) { return idx1 * cols + idx2; }

    std::vector<_T> data;
    size_t rows;
    size_t cols;
};

/*
 * Definitions
 */

template <typename _T>
inline Vector2D<_T>::Vector2D(size_t s1, size_t s2) : rows(s1), cols(s2)
{
    data.resize(rows * cols);
}

template <typename _T>
inline _T & Vector2D<_T>::elem(size_t idx1, size_t idx2)
{
    if (idx1 >= rows || idx2 >= cols)
        throw std::out_of_range("Index exceeds size of vector");

    return data[getIdx(idx1, idx2)];
}

template <typename _T>
inline void Vector2D<_T>::show()
{
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            std::cout << data[getIdx(i, j)] << "\t";
         }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
