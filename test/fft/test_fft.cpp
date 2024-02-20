#include <gtest/gtest.h>
#include <cstdlib>

#include "naive_complex.h"
#include "fft.h"

using namespace ComplexSpace;
using std::vector;

Float random_float()
{
    return Float(std::rand()) / Float(RAND_MAX);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

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
