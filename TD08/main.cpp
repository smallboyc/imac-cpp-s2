#include <iostream>
#include <string>
#include "RLE.hpp"
#include "HE.hpp"

int main()
{
    // Exercice 1
    std::string str{"AAAABBBCCDAA"};
    std::string str_RLE{"12A3B2C1D2A"};
    std::string str_RLE_control{"*4A*3B*2CD*2A"};
    std::cout << "RLE > " << str << " = " << RLE(str) << std::endl;
    std::cout << "RLE reverse > " << str_RLE << " = " << RLE_reverse(str_RLE) << std::endl;
    std::cout << "RLE control > " << str << " = " << RLE_control(str) << std::endl;
    std::cout << "RLE control reverse > " << str_RLE_control << " = " << RLE_control_reverse(str_RLE_control) << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Exercice 2
    std::cout << frequency(str) << std::endl;
    return 0;
}