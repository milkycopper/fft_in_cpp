#pragma once

#include "fft.h"
#include "common.h"

using namespace ComplexSpace;
using std::vector;

TEST(FFT, RecursiveOutOfPlaceDecimateInFreqFFT)
{
    vector<Complex> input;
    auto n = 1 << 10;

    for (auto i = 0; i < n; i++)
    {
        input.push_back(Complex(random_float(), random_float()));
    }

    auto output_a = FFT::naive_dft(input);
    auto output_b = FFT::RecursiveMethods::OutOfPlaceMethods::DecimateInFreq::fft(input);

    for (auto i = 0; i < n; i++)
    {
        ASSERT_TRUE(output_a[i].abs_diff_eq(output_b[i], Float::epsilon() * 1e6));
    }

    auto inverse_output_a = FFT::naive_inverse_dft(output_a);
    auto inverse_output_b = FFT::RecursiveMethods::OutOfPlaceMethods::DecimateInFreq::inverse_fft(output_b);

    for (auto i = 0; i < n; i++)
    {
        ASSERT_TRUE(inverse_output_a[i].abs_diff_eq(inverse_output_b[i], Float::epsilon() * 1e4));
    }

    for (auto i = 0; i < n; i++)
    {
        ASSERT_TRUE(inverse_output_a[i].abs_diff_eq(input[i], Float::epsilon() * 1e4));
        ASSERT_TRUE(inverse_output_b[i].abs_diff_eq(input[i], Float::epsilon() * 1e1));
    }
}
