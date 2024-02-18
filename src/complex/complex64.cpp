#include <cmath>
#include <cassert>
#include <limits>

#include "complex64.h"

Complex64 Complex64::operator+(const Complex64 &rhs)
{
    return Complex64(real + rhs.real, imag + rhs.imag);
}

Complex64 Complex64::operator-(const Complex64 &rhs)
{
    return Complex64(real - rhs.real, imag - rhs.imag);
}

Complex64 Complex64::operator*(const Complex64 &rhs)
{
    Float r = real * rhs.real - imag * rhs.imag;
    Float i = real * rhs.imag + imag * rhs.real;
    return Complex64(r, i);
}

Complex64 Complex64::operator/(const Complex64 &rhs)
{
    Float norm_square = rhs.real * rhs.real + rhs.imag + rhs.imag;
    Float r = (real * rhs.real + imag * rhs.imag) / norm_square;
    Float i = (imag * rhs.real + real * rhs.imag) / norm_square;
    return Complex64(r, i);
}

bool Complex64::abs_diff_eq(const Complex64 &rhs, const Float &epsilon)
{
    assert(epsilon > 0.0);
    return fabs(real - rhs.real) < epsilon && fabs(imag - rhs.imag) < epsilon;
}

bool Complex64::abs_diff_eq(const Complex64 &rhs)
{
    return Complex64::abs_diff_eq(rhs, std::numeric_limits<Float>::epsilon());
}