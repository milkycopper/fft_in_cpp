#include "naive_complex.h"

namespace ComplexSpace
{
    Complex Complex::operator+(const Complex &rhs) const
    {
        return Complex(real + rhs.real, imag + rhs.imag);
    }

    Complex Complex::operator-(const Complex &rhs) const
    {
        return Complex(real - rhs.real, imag - rhs.imag);
    }

    Complex Complex::operator*(const Complex &rhs) const
    {
        Float r = real * rhs.real - imag * rhs.imag;
        Float i = real * rhs.imag + imag * rhs.real;
        return Complex(r, i);
    }

    Complex Complex::operator/(const Complex &rhs) const
    {
        Float norm_square = rhs.real * rhs.real + rhs.imag * rhs.imag;
        Float r = (real * rhs.real + imag * rhs.imag) / norm_square;
        Float i = (imag * rhs.real - real * rhs.imag) / norm_square;
        return Complex(r, i);
    }

    Complex Complex::operator-() const
    {
        return Complex(-real, -imag);
    }

    void Complex::operator+=(const Complex &rhs)
    {
        real += rhs.real;
        imag += rhs.imag;
    }

    void Complex::operator-=(const Complex &rhs)
    {
        real -= rhs.real;
        imag -= rhs.imag;
    }

    void Complex::operator*=(const Complex &rhs)
    {
        Float r = real * rhs.real - imag * rhs.imag;
        Float i = real * rhs.imag + imag * rhs.real;
        real = r;
        imag = i;
    }

    void Complex::operator/=(const Complex &rhs)
    {
        Float norm_square = rhs.real * rhs.real + rhs.imag * rhs.imag;
        Float r = (real * rhs.real + imag * rhs.imag) / norm_square;
        Float i = (imag * rhs.real - real * rhs.imag) / norm_square;
        real = r;
        imag = i;
    }

    std::istream &operator>>(std::istream &in, Complex &x)
    {
        in >> x.real >> x.imag;
        return in;
    }

    std::ostream &operator<<(std::ostream &out, Complex &x)
    {
        out << x.real << " + " << x.imag << " i";
        return out;
    }

    bool Complex::abs_diff_eq(const Complex &rhs, const Float &epsilon) const
    {
        return real.abs_diff_eq(rhs.real, epsilon) && imag.abs_diff_eq(rhs.imag, epsilon);
    }

    bool Complex::abs_diff_eq(const Complex &rhs) const
    {
        return abs_diff_eq(rhs, Float::epsilon());
    }

    Float Complex::norm() const
    {
        return (real * real + imag * imag).sqrt();
    }

    Float Complex::arg() const
    {
        return (imag / real).atan();
    }

    Complex Complex::from_norm_angle(Float norm, Float angle)
    {
        return Complex(norm * angle.cos(), norm * angle.sin());
    }

    Complex Complex::from_angle(Float angle)
    {
        return Complex(angle.cos(), angle.sin());
    }

    Complex Complex::primitive(unsigned long n)
    {
        return Complex::from_angle(-(Float::pi() * 2.0 / static_cast<FloatSpace::InnerFloat>(n)));
    }

    Complex Complex::primitive_pow(unsigned long n, unsigned long k)
    {
        unsigned long reminder = k % n;
        return Complex::from_angle(-(Float::pi() * 2.0 * static_cast<FloatSpace::InnerFloat>(k)) / static_cast<FloatSpace::InnerFloat>(n));
    }

    Complex Complex::conjugate() const
    {
        return Complex(real, -imag);
    }

    Complex Complex::scale(Float s) const
    {
        return Complex(real * s, imag * s);
    }
}