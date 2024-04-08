#include <iostream>
#include <string>
#include <vector>
#include <iterator>

auto const is_space = [](char letter)
{
    return letter == ' ';
};

int firstWordSize(std::string const &s)
{
    auto it = std::find_if(s.begin(), s.end(), is_space);
    return std::distance(s.begin(), it);
}

//Méthode 2 pour split_string
std::vector<std::string> split_string(std::string const &s)
{
    std::vector<std::string> result;
    auto it_start{s.begin()};
    while (it_start != s.end())
    {
        std::string word;
        auto it_space{std::find_if(it_start, s.end(), is_space)};
        int word_size = std::distance(it_start, it_space);
        for (auto it = it_start; it != it_space; it++)
            word += *it;
        result.push_back(word);
        if (it_space != s.end())
            it_start += word_size + 1;
        else
            break;
    }
    return result;
}

//Méthode 1 pour split_string
// std::vector<std::string> split_string(std::string const &s)
// {
//     std::vector<std::string> result;
//     std::string word;

//     for (auto it{s.begin()}; it != s.end(); it++)
//     {
//         // à chaque ' ' on ajoute le mot au vector final
//         if (*it == ' ')
//         {
//             result.push_back(word);
//             word.clear();
//         }
//         // construction du mot
//         else
//             word += *it;
//     }
//     // ajout du dernier mot
//     result.push_back(word);
//     return result;
// }

int main()
{
    std::string s{"Milan beau goss du 77"};
    std::cout << "Nombre de lettres du premier mot : " << firstWordSize(s);
    std::cout << std::endl;
    for (std::string const element : split_string(s))
        std::cout << element << std::endl;
    return 0;
}