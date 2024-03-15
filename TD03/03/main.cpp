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
    std::vector<Token> NPI_RESULT{infix_to_npi_tokens(str)};
    display_NPI_Result(NPI_RESULT);

    return 0;
}