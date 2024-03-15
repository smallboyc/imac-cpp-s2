#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <math.h>
#include <stack>
#include "function.hpp"

int main()
{
    std::string str{};
    std::cout << "Entrez une chaine : ";
    std::getline(std::cin, str);
    std::cout << str;
    std::cout << std::endl;
    std::vector<std::string> tokens{split_string(str)};
    std::cout << npi_evaluate(tokenize(tokens));
    return 0;
}