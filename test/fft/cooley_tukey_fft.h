#pragma once

#include "fft.h"
#include "common.h"

using namespace ComplexSpace;
using std::vector;

TEST(FFT, CooleyTukeyFFT)
{
    vector<Complex> input_a;
    auto n = 1 << 14;

    for (auto i = 0; i < n; i++)
    {
        input_a.push_back(Complex(random_float(), random_float()));
    }

    vector<Complex> input_b(input_a);

    auto output_a = FFT::RecursiveMethods::OutOfPlaceMethods::DecimateInFreq::fft(input_a);
    FFT::CircularMethods::InplaceMethods::CooleyTukey::fft(input_b);

    for (auto i = 0; i < n; i++)
    {
        ASSERT_TRUE(output_a[i].abs_diff_eq(input_b[i], 1e3));
    }

    FFT::CircularMethods::InplaceMethods::CooleyTukey::inverse_fft(input_b);
    for (auto i = 0; i < n; i++)
    {
        ASSERT_TRUE(input_a[i].abs_diff_eq(input_b[i], 1e1));
    }
}