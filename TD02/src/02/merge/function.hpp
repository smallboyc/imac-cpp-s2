#pragma once
#include <iostream>
#include <vector>

void merge_sort_merge(std::vector<float> &vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<float> &vec, size_t const left, size_t const right);
void merge_sort(std::vector<float> &vec);