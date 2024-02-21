#include <vector>
#include <cassert>

#include "fft.h"
#include "naive_complex.h"

namespace FFT
{
    using ComplexSpace::Complex;
    using FloatSpace::Float;
    using std::vector;

    namespace RecursiveMethods
    {
        namespace OutOfPlaceMethods
        {
            namespace DecimateInFreq
            {
                vector<Complex> inverse_fft_inner(const vector<Complex> &input, const bool is_first_time);

                vector<Complex> fft(const vector<Complex> &input)
                {
                    const auto n = input.size();
                    if (n <= 1)
                    {
                        return vector<Complex>(input);
                    }

                    assert(size_is_power_of_2(n));

                    const vector<Complex> &x = input;
                    vector<Complex> y(n);

                    vector<Complex> x_a;
                    vector<Complex> x_b;

                    for (auto i = 0; i < n / 2; i++)
                    {
                        x_a.push_back(x[i] + x[i + n / 2]);
                        x_b.push_back((x[i] - x[i + n / 2]) * Complex::primitive_pow(n, i));
                    }

                    auto y_a = fft(x_a);
                    auto y_b = fft(x_b);

                    for (auto i = 0; i < n / 2; i++)
                    {
                        y[2 * i] = y_a[i];
                        y[2 * i + 1] = y_b[i];
                    }

                    return y;
                }

                vector<Complex> inverse_fft(const vector<Complex> &input)
                {
                    return inverse_fft_inner(input, true);
                }

                vector<Complex> inverse_fft_inner(const vector<Complex> &input, const bool is_first_time)
                {
                    const auto n = input.size();
                    if (n <= 1)
                    {
                        return vector<Complex>(input);
                    }

                    if (is_first_time)
                    {
                        assert(size_is_power_of_2(n));
                    }

                    const Float n_recip(1.0 / static_cast<FloatSpace::InnerFloat>(n));
                    const vector<Complex> &y = input;
                    vector<Complex> x(n);

                    vector<Complex> y_a;
                    vector<Complex> y_b;

                    for (auto i = 0; i < n / 2; i++)
                    {
                        y_a.push_back(y[i] + y[i + n / 2]);
                        y_b.push_back((y[i] - y[i + n / 2]) * Complex::primitive_pow(n, i).conjugate());
                    }

                    auto x_a = inverse_fft_inner(y_a, false);
                    auto x_b = inverse_fft_inner(y_b, false);

                    for (auto i = 0; i < n / 2; i++)
                    {
                        x[2 * i] = x_a[i];
                        x[2 * i + 1] = x_b[i];
                    }

                    if (is_first_time)
                    {
                        for (auto i = 0; i < n; i++)
                        {
                            x[i].real *= n_recip;
                            x[i].imag *= n_recip;
                        }
                    }

                    return x;
                }
            }

        }
    }
}