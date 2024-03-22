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

std::vector<std::string> split_string(std::string const &s)
{
    std::vector<std::string> result;
    std::string word;
    size_t last_element{s.size() - 1};

    for (auto it{s.begin()}; it != s.end(); it++)
    {
        // à chaque ' ' on ajoute le mot au vector final
        if (*it == ' ')
        {
            result.push_back(word);
            word.clear();
        }
        // construction du mot
        else
            word += *it;
    }
    // ajout du dernier mot
    result.push_back(word);
    return result;
}

int main()
{
    std::string s{"Milan beau goss du 77"};
    std::cout << "Nombre de lettres du premier mot : " << firstWordSize(s);
    std::cout << std::endl;
    for (std::string const element : split_string(s))
        std::cout << element << std::endl;
    return 0;
}