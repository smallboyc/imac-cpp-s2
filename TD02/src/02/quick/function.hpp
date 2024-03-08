#pragma once
#include <iostream>
#include <vector>

size_t quick_sort_partition(std::vector<float> &vec, size_t left, size_t right, size_t const pivot);
void quick_sort(std::vector<float> &vec, size_t const left, size_t const right);
void quick_sort(std::vector<float> &vec);