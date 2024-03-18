#include <iostream>
#include <vector>

int checkMaxNumber(std::vector<int> const &array)
{
    int max{0};
    for (int i{0}; i < array.size(); i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

std::vector<int> sortArray(std::vector<int> const &array, int const &max)
{
    std::vector<int> iterationArray(max + 1);
    std::vector<int> final;
    for (int i{0}; i < iterationArray.size(); i++)
    {
        for (int j{0}; j < array.size(); j++)
        {
            if (i == array[j])
                iterationArray[i]++;
        }
        if (iterationArray[i] != 0)
            for (int j{0}; j < iterationArray[i]; j++)
                final.push_back(i);
    }
    return final;
}

void display(std::vector<int> const &vec)
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

int main()
{
    // std::vector<int> array{1, 4, 1, 2, 7, 5, 2};
    std::vector<int> array{2, 1, 2, 3, 7, 6, 5, 2, 17, 18};
    display(sortArray(array, checkMaxNumber(array)));
    return 0;
}