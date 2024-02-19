#pragma once

#ifdef FLOAT_32
#ifndef FLOAT_64
typedef float InnerFloat;
typedef unsigned int UInt;
#define BITS_WIDTH 32
#endif
#endif

#ifdef FLOAT_64
#ifndef FLOAT_32
typedef double InnerFloat;
typedef unsigned long UInt;
#define BITS_WIDTH 64
#endif
#endif

class Float
{
public:
    Float(const InnerFloat x) : inner(x) {}
    Float(const Float &x)
    {
        inner = x.inner;
    }

    Float operator+(const Float &rhs) const;
    Float operator-(const Float &rhs) const;
    Float operator*(const Float &rhs) const;
    Float operator/(const Float &rhs) const;
    Float operator-() const;

    void operator+=(const Float &rhs);
    void operator-=(const Float &rhs);
    void operator*=(const Float &rhs);
    void operator/=(const Float &rhs);

    Float abs() const;

private:
    InnerFloat inner;
    UInt to_bits() const;
};
