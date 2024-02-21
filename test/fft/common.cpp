#include "common.h"

Float random_float()
{
    return Float(std::rand()) / Float(RAND_MAX);
}

std::vector<Float> random_float_vector(size_t n)
{
    std::vector<Float> data;

    for (auto i = 0; i < n; i++)
    {
        data.push_back(random_float());
    }

    return data;
}

std::vector<Complex> random_complex_vector(size_t n)
{
    std::vector<Complex> data;

    for (auto i = 0; i < n; i++)
    {
        data.push_back(Complex(random_float(), random_float()));
    }

    return data;
}
