#include <vector>
#include <cassert>

#include "complex.h"
#include "fft.h"

namespace FFT
{
    using std::vector;

    namespace CircularMethods
    {
        namespace InplaceMethods
        {
            namespace CooleyTukey
            {
                size_t bit_rev(size_t x, size_t lgn)
                {
                    size_t value = 0;

                    for (auto i = lgn; i != 0; i--)
                    {
                        value |= (1 & x) << (i - 1);
                        x >>= 1;
                    }

                    return value;
                }

                void fft(vector<Complex> &input)
                {
                    const auto n = input.size();
                    if (n <= 1)
                    {
                        return;
                    }

                    assert(size_is_power_of_2(n));

                    auto &x = input;
                    auto len = n;
                    const auto m = power_with_base_2(n);

                    for (auto k = 0; k < m; k++)
                    {
                        len = len / 2;
                        for (auto j = 0; j < len; j++)
                        {
                            for (auto i = j; i < n; i += len * 2)
                            {
                                auto temp = x[i] - x[i + len];
                                x[i] += x[i + len];
                                x[i + len] = temp * Complex::primitive_pow(len * 2, j);
                            }
                        }
                    }

                    vector<Complex> z(x);
                    for (int i = 0; i < n; i++)
                    {
                        x[i] = z[bit_rev(i, m)];
                    }

                    return;
                }

                void inverse_fft(vector<Complex> &input)
                {
                    const auto n = input.size();
                    if (n <= 1)
                    {
                        return;
                    }

                    assert(size_is_power_of_2(n));

                    auto &x = input;
                    auto len = n;
                    const auto m = power_with_base_2(n);

                    for (auto k = 0; k < m; k++)
                    {
                        len = len / 2;
                        for (auto j = 0; j < len; j++)
                        {
                            for (auto i = j; i < n; i += len * 2)
                            {
                                auto temp = x[i] - x[i + len];
                                x[i] += x[i + len];
                                x[i + len] = temp * Complex::primitive_pow(len * 2, j).conjugate();
                            }
                        }
                    }

                    vector<Complex> z(x);
                    for (int i = 0; i < n; i++)
                    {
                        x[i] = z[bit_rev(i, m)];
                    }

                    const auto n_recip = 1.0 / static_cast<FloatSpace::InnerFloat>(n);
                    for (auto i = 0; i < n; i++)
                    {
                        x[i].real *= n_recip;
                        x[i].imag *= n_recip;
                    }

                    return;
                }
            }
        }
    }
}