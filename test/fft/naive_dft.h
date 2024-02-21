#pragma once

#include "fft.h"
#include "common.h"

using namespace ComplexSpace;
using std::vector;

TEST(FFT, NaiveDFT)
{
    auto n = 1000;
    vector<Complex> input = random_complex_vector(n);

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

    ASSERT_TRUE(vector_abs_diff_eq(input, inverse_output, Float::epsilon() * 1e4));
}