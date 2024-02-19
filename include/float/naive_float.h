#pragma once

#ifdef FLOAT_32
#ifndef FLOAT_64
typedef float InnerFloat;
#endif
#endif

#ifdef FLOAT_64
#ifndef FLOAT_32
typedef double InnerFloat;
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

    bool operator>(const Float &rhs) const;
    bool operator>=(const Float &rhs) const;
    bool operator<(const Float &rhs) const;
    bool operator<=(const Float &rhs) const;

    Float abs() const;
    bool abs_diff_eq(const Float &rhs, const Float &epsilon) const;
    bool abs_diff_eq(const Float &rhs) const;

    Float epsilon() const;

    Float max(const Float &rhs) const;
    Float min(const Float &rhs) const;

private:
    InnerFloat inner;
};
