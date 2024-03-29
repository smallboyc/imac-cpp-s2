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
    std::cout << "Entrez une chaine (notation infixe): ";
    std::getline(std::cin, str);
    std::cout << str;
    std::cout << std::endl;
    std::cout << "notation NPI : ";
    display_NPI_Result(infix_to_npi_tokens(str));
    std::cout << " => ";
    std::cout << npi_evaluate(infix_to_npi_tokens(str));
    return 0;
}