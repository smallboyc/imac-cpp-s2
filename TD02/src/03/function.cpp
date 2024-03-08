#include <iostream>
#include <vector>
#include "function.hpp"

// BUBBLE

void bubble_sort(std::vector<float> &vec)
{
    int j{1};
    while (!is_sorted(vec))
    {
        for (int i{0}; i < vec.size() - j; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                int temp = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = temp;
            }
        }
        j++;
    }
}

// SELECTION

void selection_sort(std::vector<float> &vec)
{
    float smallest{vec[0]};
    float smallest_id{0};
    for (int i{0}; i < vec.size(); i++)
    {
        if (vec[i] < smallest)
        {
            smallest = vec[i];
        }
    }
    while (!is_sorted(vec))
    {
        for (int i{0}; i < vec.size(); i++)
        {
            if (vec[i] == smallest)
            {
                float tmp = vec[smallest_id];
                vec[smallest_id] = smallest;
                vec[i] = tmp;
                smallest_id++;
            }
        }
        smallest++;
    }
}

// IS SORTED?

bool is_sorted(std::vector<float> &vec) { return std::is_sorted(vec.begin(), vec.end()); }

// MERGE

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

// QUICK

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
