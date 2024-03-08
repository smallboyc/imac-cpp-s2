#include <iostream>
#include <vector>
#include "function.hpp"
#include "utils.hpp"

int main()
{
    std::vector<float> vector{9, 5, 2, 6, 8, 1, 3, 1, 2, 3};
    std::cout << "Tableau non trié : " << std::endl;
    display(vector);
    quick_sort(vector);
    std::cout << std::endl;
    std::cout << "Tableau trié : " << std::endl;
    display(vector);
    return 0;
}