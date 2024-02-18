#pragma once

typedef double Float;

class Complex64
{
public:
    Float real;
    Float imag;

    Complex64(Float real, Float imag) : real(real), imag(imag) {}

    Complex64 operator+(const Complex64 &rhs);
    Complex64 operator-(const Complex64 &rhs);
    Complex64 operator*(const Complex64 &rhs);
    Complex64 operator/(const Complex64 &rhs);
    bool abs_diff_eq(const Complex64 &rhs, const Float &epsilon);
    bool abs_diff_eq(const Complex64 &rhs);
};