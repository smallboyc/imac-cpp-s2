#include <iostream>
#include <vector>
#include "function.hpp"

void bubble_sort(std::vector<int> &vec)
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

void selection_sort(std::vector<int> &vec)
{
    int smallest{vec[0]};
    int smallest_id{0};
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
                int tmp = vec[smallest_id];
                vec[smallest_id] = smallest;
                vec[i] = tmp;
                smallest_id++;
            }
        }
        smallest++;
    }
}

bool is_sorted(std::vector<int> &vec) { return std::is_sorted(vec.begin(), vec.end()); }