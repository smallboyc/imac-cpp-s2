#include <iostream>
#include <vector>
#include "function.hpp"

int main()
{
    std::vector<float> vector{6, 1, 3, 5, 4, 2, 9, 8};
    std::cout << "Tableau non trié : " << std::endl;
    display(vector);
    std::cout << std::endl;

    merge_sort(vector);

    std::cout << "Tableau trié : " << std::endl;
    display(vector);
    return 0;
}