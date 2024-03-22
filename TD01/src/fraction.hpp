#include <iostream>
#pragma once

struct Fraction
{
    unsigned int numerator;
    unsigned int denominator;
    void operator+=(Fraction const &f);
    void operator-=(Fraction const &f);
    void operator*=(Fraction const &f);
    void operator/=(Fraction const &f);
    float to_float() const;
    operator float() const;
    float abs();
    float ceil();
    float floor();
    float round();
};

std::ostream &operator<<(std::ostream &os, Fraction const &p);
Fraction operator+(Fraction const &f1, Fraction const &f2);
Fraction operator+(const Fraction &f, int const i);
Fraction operator+(int const i, const Fraction &f);
Fraction operator-(Fraction const &f1, Fraction const &f2);
Fraction operator*(Fraction const &f1, Fraction const &f2);
Fraction operator/(Fraction const &f1, Fraction const &f2);
bool operator==(Fraction const &f1, Fraction const &f2);
bool operator!=(Fraction const &f1, Fraction const &f2);
bool operator>(Fraction const &f1, Fraction const &f2);
bool operator<(Fraction const &f1, Fraction const &f2);
bool operator>=(Fraction const &f1, Fraction const &f2);
bool operator<=(Fraction const &f1, Fraction const &f2);