#include <iostream>
#include <vector>
#include "function.hpp"

size_t quick_sort_partition(std::vector<float> &vec, size_t left, size_t right, size_t const pivot)
{
    size_t j{left};
    for (size_t i{left}; i <= right; i++)
    {
        if (vec[i] <= pivot)
        {
            size_t tmp{static_cast<size_t>(vec[i])};
            vec[i] = vec[j];
            vec[j] = tmp;
            j++;
        }
    }
    return j - 1;
}
void quick_sort(std::vector<float> &vec, size_t const left, size_t const right)
{
    if (left < right)
    {
        size_t const PIVOT{static_cast<size_t>(vec[right])};
        size_t PIVOT_INDEX{quick_sort_partition(vec, left, right, PIVOT)};
        quick_sort(vec, left, PIVOT_INDEX - 1);
        quick_sort(vec, PIVOT_INDEX + 1, right);
    }
}
void quick_sort(std::vector<float> &vec)
{
    quick_sort(vec, 0, vec.size() - 1);
}