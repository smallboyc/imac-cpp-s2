#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> v;
    int vector_size{5};
    int number{0};
    int init{0};

    for (int i{0}; i < vector_size; i++)
        v.push_back(rand() % 100 + 1);

    std::cout << "Entrez un nombre entre 0 et " << vector_size << " :";
    std::cin >> number;

    // Affiche les éléments du vector (méthode 1)
    for (auto it{v.begin()}; it != v.end(); ++it)
        std::cout << *it << ", ";

    std::cout << std::endl;

    // Trier le vector
    std::sort(v.begin(), v.end());
    // Affiche les éléments du vector (méthode 2)
    std::cout << "Vector trié : " << std::endl;
    for (int element : v)
        std::cout << element << ", ";

    std::cout << std::endl;

    // Check la présence de number dans le vector
    //  return la position de number si trouvé / sinon => v.end()
    auto it{std::find(v.begin(), v.end(), number)};
    if (it != v.end())
        std::cout << *it << " est bien présent dans le vector" << std::endl;
    else
        std::cout << number << " n'est pas présent dans le vector";

    std::cout << std::endl;

    // Nombre d'occurences de number
    const int occurences = std::count(v.begin(), v.end(), 45);
    std::cout << "Nombre d'occurences pour " << number << " : " << occurences << " " << std::endl;

    std::cout << std::endl;
    // Somme du vector
    std::cout << "Somme du vector : ";
    std::cout << std::accumulate(v.begin(), v.end(), init);
    return 0;
}