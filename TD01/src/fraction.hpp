#include <iostream>
#pragma once

struct Fraction
{
    unsigned int numerator;
    unsigned int denominator;
};

std::ostream &operator<<(std::ostream &os, Fraction const &p);
Fraction operator+(Fraction const &f1, Fraction const &f2);
Fraction operator-(Fraction const &f1, Fraction const &f2);
Fraction operator*(Fraction const &f1, Fraction const &f2);
Fraction operator/(Fraction const &f1, Fraction const &f2);