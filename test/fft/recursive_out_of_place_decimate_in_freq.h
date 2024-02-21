#pragma once

#include "fft.h"
#include "common.h"

using namespace ComplexSpace;
using std::vector;

TEST(FFT, RecursiveOutOfPlaceDecimateInFreqFFT)
{
    auto n = 1 << 10;
    vector<Complex> input = random_complex_vector(n);

    auto output_a = FFT::naive_dft(input);
    auto output_b = FFT::RecursiveMethods::OutOfPlaceMethods::DecimateInFreq::fft(input);

    ASSERT_TRUE(vector_abs_diff_eq(output_a, output_b, Float::epsilon() * 1e6));

    auto inverse_output_a = FFT::naive_inverse_dft(output_a);
    auto inverse_output_b = FFT::RecursiveMethods::OutOfPlaceMethods::DecimateInFreq::inverse_fft(output_b);

    ASSERT_TRUE(vector_abs_diff_eq(inverse_output_a, inverse_output_b, Float::epsilon() * 1e4));
    ASSERT_TRUE(vector_abs_diff_eq(inverse_output_a, input, Float::epsilon() * 1e4));
    ASSERT_TRUE(vector_abs_diff_eq(inverse_output_b, input, Float::epsilon() * 1e1));
}
