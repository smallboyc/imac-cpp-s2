#include "fraction.hpp"
#include "utils.hpp"
#include <iostream>
#include <math.h>

std::ostream &operator<<(std::ostream &os, Fraction const &p)
{
    return os << p.numerator << " / " << p.denominator;
}

Fraction operator+(Fraction const &f1, Fraction const &f2)
{
    Fraction result = f1;
    result += f2;
    return (simplify(result));
}
Fraction operator+(const Fraction &f, int const i)
{
    Fraction result = f;
    Fraction intToFraction{static_cast<unsigned int>(i), static_cast<unsigned int>(1)};
    result += intToFraction;
    return (simplify(result));
}
Fraction operator+(int const i, const Fraction &f)
{
    return f + i;
}

Fraction operator-(Fraction const &f1, Fraction const &f2)
{
    Fraction result = f1;
    result -= f2;
    return (simplify(result));
}
Fraction operator*(Fraction const &f1, Fraction const &f2)
{
    Fraction result = f1;
    result *= f2;
    return (simplify(result));
}
Fraction operator/(Fraction const &f1, Fraction const &f2)
{
    Fraction result = f1;
    result /= f2;
    return (simplify(result));
}

void Fraction::operator+=(Fraction const &f)
{
    numerator = numerator * f.denominator + f.numerator * denominator;
    denominator *= f.denominator;
}
void Fraction::operator-=(Fraction const &f)
{
    numerator = numerator * f.denominator - f.numerator * denominator;
    denominator *= f.denominator;
}
void Fraction::operator*=(Fraction const &f)
{
    numerator *= f.numerator,
        denominator *= f.denominator;
}
void Fraction::operator/=(Fraction const &f)
{
    numerator *= f.denominator;
    denominator *= f.numerator;
}

bool operator==(Fraction const &f1, Fraction const &f2)
{
    return f1.numerator * f2.denominator == f2.numerator * f1.denominator;
}
bool operator!=(Fraction const &f1, Fraction const &f2)
{
    return !(f1 == f2);
}
bool operator<(Fraction const &f1, Fraction const &f2)
{
    return static_cast<float>(f1) < static_cast<float>(f2);
}
bool operator>(Fraction const &f1, Fraction const &f2)
{
    return !(f1 < f2) && !(f1 == f2);
}
bool operator<=(Fraction const &f1, Fraction const &f2)
{
    return (f1 < f2) || (f1 == f2);
}
bool operator>=(Fraction const &f1, Fraction const &f2)
{
    return (f1 > f2) || (f1 == f2);
}

Fraction::operator float() const
{
    return static_cast<float>(numerator) / static_cast<float>(denominator);
}

//Méthodes
float Fraction::abs()
{
    return std::abs(static_cast<float>(*this));
}
float Fraction::ceil()
{
    return std::ceil(static_cast<float>(*this));
}
float Fraction::floor()
{
    return std::floor(static_cast<float>(*this));
}
float Fraction::round()
{
    return std::round(static_cast<float>(*this));
}