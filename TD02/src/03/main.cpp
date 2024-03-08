#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"
#include "utils.hpp"
#include "function.hpp"

std::vector<float> generate_random_vector(size_t const size, int const max = 100)
{
    std::vector<float> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]()
                  { return std::rand() % max; });
    return vec;
}

int main()
{
    std::vector<float> array;
    array = generate_random_vector(10);
    std::cout << "Tableau non trié (initial) : " << std::endl;
    // display(array);

    // std::cout << std::endl;
    // {
    //     ScopedTimer<std::micro> timer("Sort - Standard");
    //     std::sort(array.begin(), array.end());
    //     // 24 Elements : Environ 2 microsec
    //     // 1240 Elements : Environ 80 microsec
    // }

    // std::cout << std::endl;
    // {
    //     ScopedTimer<std::micro> timer("Sort - BUBBLE");
    //     bubble_sort(array);
    //     // 24 Elements : Environ 12 microsec
    //     // 1240 Elements : Environ 16462 microsec
    // }

    // std::cout << std::endl;
    // {
    //     ScopedTimer<std::micro> timer("Sort - SELECTION");
    //     selection_sort(array);
    //     // 24 Elements : Environ 59 microsec (pas super bien implémenté de ma part je pense)
    //     // 1240 Elements : Environ 2397 microsec
    // }

    // std::cout << std::endl;
    // {
    //     ScopedTimer<std::micro> timer("Sort - QUICK");
    //     quick_sort(array);
    //     // 24 Elements : Environ 7 microsec
    //     // 1240 Elements : Environ 300 microsec
    // }

    // std::cout << std::endl;
    // {
    //     ScopedTimer<std::micro> timer("Sort - MERGE");
    //     merge_sort(array);
    //     // 24 Elements : Environ 44 microsec => Tableaux intermédiaires qui font perdre du temps je pense
    //     // 1240 Elements : Environ 1668 microsec => Tableaux intermédiaires qui font perdre du temps je pense
    // }

    // display(array);

    // On remarque que les temps de traitements sont relativements rapides dans tous les algos de tri.
    // Cependant, le temps peut devenir important dans des projets plus conséquents.
    // L'implémentation récursive est intéressante (bien qu'assez complexe), leur efficacité est importante sur de grands tableaux
    // L'algo le plus rapide (selon mes implémentations) par rapport au tri standard est le tri rapide (quick sort) qui est proche des 7 microsecondes.

    return 0;
}