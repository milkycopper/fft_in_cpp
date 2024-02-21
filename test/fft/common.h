#pragma once

#include <vector>
#include <iostream>

#include "naive_complex.h"

using ComplexSpace::Complex;
using FloatSpace::Float;

Float random_float();
std::vector<Float> random_float_vector(size_t n);
std::vector<Complex> random_complex_vector(size_t n);

template <class T>
bool vector_abs_diff_eq(const std::vector<T> &a, const std::vector<T> &b, const Float &epsilon)
{
    if (a.size() != b.size())
    {
        return false;
    }

    for (auto i = 0; i < a.size(); i++)
    {
        if (!a[i].abs_diff_eq(b[i], epsilon))
        {
            return false;
        }
    }

    return true;
}

template <class T>
void println_vector(const std::vector<T> &v)
{
    for (auto item : v)
    {
        std::cout << item << std::endl;
    }
}
