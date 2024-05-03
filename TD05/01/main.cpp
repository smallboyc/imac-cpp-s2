#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

// 1
size_t folding_string_hash(std::string const &s, size_t max)
{
    return std::accumulate(s.begin(),
                           s.end(),
                           0,
                           [](int a, int b)
                           { return a + b; }) %
           max;
}

// 2
size_t folding_string_ordered_hash(std::string const &s, size_t max)
{
    size_t hash{0};
    for (size_t i{0}; i < s.size(); i++)
        hash += s[i] * i;
    return hash % max;
}

// 3
size_t polynomial_rolling_hash(const std::string &s, size_t p, size_t m)
{
    size_t hash{0};
    size_t power{1};
    for (size_t i{0}; i < s.size(); i++)
    {
        hash += s[i] * power;
        power *= p;
    }
    return hash % m;
}

int main()
{
    size_t MAX{2048};
    std::string s{"Je suis une phrase"};
    std::cout << folding_string_hash(s, MAX) << std::endl;
    std::cout << folding_string_ordered_hash(s, MAX) << std::endl;
    std::cout << polynomial_rolling_hash(s, 21, MAX) << std::endl;
    return 0;
}