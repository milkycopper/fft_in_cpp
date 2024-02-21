#pragma once

#include "fft.h"
#include "common.h"

using namespace ComplexSpace;
using std::vector;

TEST(FFT, BitRev)
{
    ASSERT_EQ(FFT::CircularMethods::InplaceMethods::CooleyTukey::bit_rev(3, 3), 6);
    ASSERT_EQ(FFT::CircularMethods::InplaceMethods::CooleyTukey::bit_rev(6, 3), 3);
    ASSERT_EQ(FFT::CircularMethods::InplaceMethods::CooleyTukey::bit_rev(4, 3), 1);
    ASSERT_EQ(FFT::CircularMethods::InplaceMethods::CooleyTukey::bit_rev(1, 3), 4);
}

TEST(FFT, CooleyTukeyFFT)
{
    auto n = 1 << 12;
    vector<Complex> input_a = random_complex_vector(n);
    vector<Complex> input_b(input_a);

    auto output_a = FFT::RecursiveMethods::OutOfPlaceMethods::DecimateInFreq::fft(input_a);
    FFT::CircularMethods::InplaceMethods::CooleyTukey::fft(input_b);

    // std::cout << "output_a = " << std::endl;
    // println_vector(output_a);
    // std::cout << "input_b = " << std::endl;
    // println_vector(input_b);

    ASSERT_TRUE(vector_abs_diff_eq(output_a, input_b, Float::epsilon() * 1e1));

    FFT::CircularMethods::InplaceMethods::CooleyTukey::inverse_fft(input_b);
    ASSERT_TRUE(vector_abs_diff_eq(input_a, input_b, Float::epsilon() * 1e1));
}