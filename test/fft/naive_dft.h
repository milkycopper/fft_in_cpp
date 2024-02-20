#pragma once

#include "fft.h"
#include "common.h"

using namespace ComplexSpace;
using std::vector;

TEST(FFT, NaiveDFT)
{
    vector<Complex> input;
    auto n = 1000;

    for (auto i = 0; i < n; i++)
    {
        input.push_back(Complex(random_float(), random_float()));
    }

    auto output = FFT::naive_dft(input);

    // std::cout << "output of naive dft = " << std::endl;
    // for (auto item : output)
    // {
    //     std::cout << item << std::endl;
    // }

    auto inverse_output = FFT::naive_inverse_dft(output);

    // std::cout << "output of naive inverse dft = " << std::endl;
    // for (auto item : inverse_output)
    // {
    //     std::cout << item << std::endl;
    // }

    for (auto i = 0; i < n; i++)
    {
        ASSERT_TRUE(input[i].abs_diff_eq(inverse_output[i], Float::epsilon() * 1e4));
    }
}