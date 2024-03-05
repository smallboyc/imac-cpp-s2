#include <iostream>
#include <vector>
#include <algorithm>
#include "function.hpp"

int main()
{
    std::vector<int> vec{9, 3, 7, 4, 5, 1, 6, 2, 8, 1};
    std::cout << "Tableau avant (pas trié) : " << std::endl;
    display(vec);

    std::cout << std::endl;
    std::cout << std::endl;

    // Tri à bulle
    // bubble_sort(vec);

    // Tri par sélection
    selection_sort(vec);

    std::cout << "Tableau après (trié) : " << std::endl;
    display(vec);
    return 0;
}