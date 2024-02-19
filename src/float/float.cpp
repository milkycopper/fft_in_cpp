#include "naive_float.h"

Float float_from_bits(UInt x)
{
    return Float(*reinterpret_cast<InnerFloat *>(&x));
}

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

UInt Float::to_bits() const
{
    InnerFloat x0 = inner;
    return *reinterpret_cast<UInt *>(&x0);
}

Float Float::abs() const
{
    UInt mask = (1 << (BITS_WIDTH - 1)) - 1;
    UInt bits = this->to_bits() & mask;
    return float_from_bits(bits);
}