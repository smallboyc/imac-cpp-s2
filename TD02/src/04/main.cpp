#include <iostream>
#include <vector>
#include <algorithm>

void display(std::vector<int> &vec)
{
    std::cout << "[";
    for (int i{0}; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]";
}

int search(std::vector<int> &vec, int const left, int const right, int const target)
{
    if (left > right)
        return -1;
    int MIDDLE{(left + right) / 2};
    if (vec[MIDDLE] < target)
        return search(vec, MIDDLE + 1, right, target);
    else if (vec[MIDDLE] > target)
        return search(vec, left, MIDDLE - 1, target);
    else if (vec[MIDDLE] == target)
        return MIDDLE;
    return -1;
}

void dichotomy(std::vector<int> array, int const target)
{
    std::sort(array.begin(), array.end());
    std::cout << std::endl;
    std::cout << search(array, 0, array.size() - 1, target);
}

int main()
{
    dichotomy({7, 4, 2, 8, 3, 1, 9, 6}, 8);
    dichotomy({1, 2, 3, 3, 6, 14, 12, 15}, 15);
    dichotomy({2, 2, 3, 4, 5, 8, 12, 15, 16}, 16);
    dichotomy({5, 6, 7, 8, 9, 10, 11, 12, 13}, 6);
    dichotomy({1, 2, 3, 4, 5, 6, 7, 8, 9}, 10);

    return 0;
}