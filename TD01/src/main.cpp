#include <iostream>
#include "fraction.hpp"

// Tout le TD01 se trouve dans ce programme.

int main()
{
    Fraction f1{7, 2};
    Fraction f2{8, 3};
    int i{2};

    std::cout << std::endl;
    std::cout << "f1 = " << f1 << " = " << static_cast<float>(f1) << std::endl;
    std::cout << "f2 = " << f2 << " = " << static_cast<float>(f2) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    if (f1 == f2)
        std::cout << "Les fractions sont égales." << std::endl;
    else
        std::cout << "Les fractions sont différentes." << std::endl;

    std::cout << std::endl;

    if (f1 < f2)
        std::cout << f1 << " est inférieur à " << f2 << std::endl;
    else if (f1 > f2)
        std::cout << f1 << " est supérieur à " << f2 << std::endl;
    else if (f1 <= f2)
        std::cout << f1 << " est plus petit ou égale à " << f2 << std::endl;
    else if (f1 >= f2)
        std::cout << f1 << " est plus grand ou égale à " << f2 << std::endl;

    std::cout << std::endl;

    std::cout << "Addition = " << (f1 + f2) << std::endl;
    std::cout << "Soustraction  = " << (f1 - f2) << std::endl;
    std::cout << "Multiplication = " << (f1 * f2) << std::endl;
    std::cout << "Division = " << (f1 / f2) << std::endl;

    std::cout << std::endl;
    std::cout << "Addition (f1 & i) = " << (i + f1) << std::endl;
    std::cout << std::endl;

    std::cout << "Valeur absolue pour f1 : " << f1.abs() << std::endl;
    std::cout << "Arrondi supérieur pour f1  : " << f1.ceil() << std::endl;
    std::cout << "Arrondi inférieur pour f1 : " << f1.floor() << std::endl;
    std::cout << "Arrondi pour f1 : " << f1.round() << std::endl;
    std::cout << std::endl;
    return 0;
}