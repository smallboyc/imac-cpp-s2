#include <iostream>
#include <vector>
#include "function.hpp"

void display(std::vector<float> &vec)
{
    for (int i{0}; i < vec.size(); i++)
    {
        std::cout << vec[i] << ", ";
    }
}

void merge_sort_merge(std::vector<float> &vec, size_t const left, size_t const middle, size_t const right)
{
    size_t LEFT_SIZE{middle - left + 1};
    size_t RIGHT_SIZE{right - middle};
    std::vector<float> vectorLeft(LEFT_SIZE);
    std::vector<float> vectorRight(RIGHT_SIZE);
    for (size_t i{0}; i < LEFT_SIZE; i++)
        vectorLeft[i] = vec[left + i];
    for (size_t j{0}; j < RIGHT_SIZE; j++)
        vectorRight[j] = vec[middle + 1 + j];

    size_t i{0};
    size_t j{0};
    size_t k{left};
    while (i < LEFT_SIZE && j < RIGHT_SIZE)
    {
        if (vectorLeft[i] <= vectorRight[j])
        {
            vec[k] = vectorLeft[i];
            i++;
        }
        else
        {
            vec[k] = vectorRight[j];
            j++;
        }
        k++;
    }

    // Copie des éléments restants de vectorLeft s'il y en a
    while (i < LEFT_SIZE)
    {
        vec[k] = vectorLeft[i];
        i++;
        k++;
    }

    // Copie des éléments restants de vectorRight s'il y en a
    while (j < RIGHT_SIZE)
    {
        vec[k] = vectorRight[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<float> &vec, size_t const left, size_t const right)
{
    if (left < right)
    {
        size_t MIDDLE{(left + right) / 2};
        // Subdivision à gauche
        merge_sort(vec, left, MIDDLE);
        // Subdivision à droite
        merge_sort(vec, MIDDLE + 1, right);
        // Fusion
        merge_sort_merge(vec, left, MIDDLE, right);
    }
}

void merge_sort(std::vector<float> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
}
