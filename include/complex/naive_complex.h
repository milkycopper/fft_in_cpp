#pragma once

#include "naive_float.h"

namespace ComplexSpace
{
    using FloatSpace::Float;

    class Complex
    {
    public:
        Float real;
        Float imag;

        Complex() : Complex(0.0, 0.0) {}
        Complex(Float real, Float imag) : real(real), imag(imag) {}

        Complex operator+(const Complex &rhs) const;
        Complex operator-(const Complex &rhs) const;
        Complex operator*(const Complex &rhs) const;
        Complex operator/(const Complex &rhs) const;
        Complex operator-() const;

        void operator+=(const Complex &rhs);
        void operator-=(const Complex &rhs);
        void operator*=(const Complex &rhs);
        void operator/=(const Complex &rhs);

        friend std::istream &operator>>(std::istream &in, Complex &x);
        friend std::ostream &operator<<(std::ostream &out, Complex &x);

        bool abs_diff_eq(const Complex &rhs, const Float &epsilon) const;
        bool abs_diff_eq(const Complex &rhs) const;

        Float norm() const;
        Float arg() const;
        Complex conjugate() const;
        Complex scale(Float s) const;

        static Complex from_norm_angle(Float norm, Float angle);
        static Complex from_angle(Float angle);
        static Complex primitive(unsigned long n);
        static Complex primitive_pow(unsigned long n, unsigned long k);
    };
};