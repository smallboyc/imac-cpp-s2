#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int square_sum(std::vector<int> const &v)
{
    return std::accumulate(v.begin(),
                           v.end(),
                           0,
                           [](int a, int b)
                           { return a + std::pow(b, 2); });
}

int pair_prod(std::vector<int> const &v)
{
    return std::accumulate(v.begin(),
                           v.end(),
                           1,
                           [](int a, int b)
                           { if (b % 2 == 0) return a * b; return a; });
}

int main()
{
    std::vector<int> v{1, 3, 24, 44, 42};
    std::cout << "La somme des carrés est égale à : " << square_sum(v);
    std::cout << std::endl;
    std::cout << "Le produit des éléments pairs est égal à : " << pair_prod(v);
    return 0;
}
