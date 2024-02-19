#include <cassert>
#include <limits>

#include "naive_float.h"

Float Float::operator+(const Float &rhs) const
{
    return Float(inner + rhs.inner);
}

Float Float::operator-(const Float &rhs) const
{
    return Float(inner - rhs.inner);
}

Float Float::operator*(const Float &rhs) const
{
    return Float(inner * rhs.inner);
}

Float Float::operator/(const Float &rhs) const
{
    return Float(inner / rhs.inner);
}

Float Float::operator-() const
{
    return Float(-inner);
}

void Float::operator+=(const Float &rhs)
{
    inner += rhs.inner;
}

void Float::operator-=(const Float &rhs)
{
    inner -= rhs.inner;
}

void Float::operator*=(const Float &rhs)
{
    inner *= rhs.inner;
}

void Float::operator/=(const Float &rhs)
{
    inner /= rhs.inner;
}

bool Float::operator>(const Float &rhs) const
{
    return inner > rhs.inner;
}

bool Float::operator>=(const Float &rhs) const
{
    return inner >= rhs.inner;
}

bool Float::operator<(const Float &rhs) const
{
    return inner < rhs.inner;
}

bool Float::operator<=(const Float &rhs) const
{
    return inner <= rhs.inner;
}

Float Float::abs() const
{
    return inner < 0.0 ? Float(-inner) : *this;
}

bool Float::abs_diff_eq(const Float &rhs, const Float &epsilon) const
{
    assert(epsilon > Float(0.0));
    return (*this - rhs).abs() < epsilon;
}

bool Float::abs_diff_eq(const Float &rhs) const
{
    return Float::abs_diff_eq(rhs, epsilon());
}

Float Float::epsilon() const
{
    return Float(std::numeric_limits<InnerFloat>::epsilon());
}

Float Float::max(const Float &rhs) const
{
    return *this > rhs ? *this : rhs;
}

Float Float::min(const Float &rhs) const
{
    return *this < rhs ? *this : rhs;
}