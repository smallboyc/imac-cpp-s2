#include <iostream>
#include <vector>
#include "function.hpp"

void display(std::vector<int> &vec)
{
    for (int i{0}; i < vec.size(); i++)
    {
        std::cout << vec[i] << ", ";
    }
}

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
    int tallest{1};
    int tallest_id{0};
    while (!is_sorted(vec))
    {
        for (int i{0}; i < vec.size(); i++)
        {
            if (vec[i] == tallest)
            {
                int tmp = vec[tallest_id];
                vec[tallest_id] = tallest;
                vec[i] = tmp;
                tallest_id++;
            }
        }
        tallest++;
    }
}

bool is_sorted(std::vector<int> &vec) { return std::is_sorted(vec.begin(), vec.end()); }