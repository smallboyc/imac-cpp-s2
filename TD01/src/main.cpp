#include <iostream>
#include "fraction.hpp"

// Tout le TD01 se trouve dans ce programme.

int main()
{
    Fraction f1{3, 4};
    Fraction f2{1, 2};

    std::cout << "f1 = ";
    std::cout << f1;
    std::cout << " f2 = ";
    std::cout << f2;
    std::cout << std::endl;

    std::cout << "add(f1, f2) = " << (f1 + f2) << std::endl;

    std::cout << "sub(f1, f2) = " << (f1 - f2) << std::endl;

    std::cout << "mul(f1, f2) = " << (f1 * f2) << std::endl;

    std::cout << "div(f1, f2) = " << (f1 / f2) << std::endl;
    return 0;
}