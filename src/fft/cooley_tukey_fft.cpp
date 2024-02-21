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

                    for (int i = 0, j = 0; i < n - 1; i++)
                    {
                        if (i < j && j < n)
                        {
                            auto temp = x[i];
                            x[i] = x[j];
                            x[j] = temp;
                        }
                        auto k = n / 2;
                        while (k < j && k > 0)
                        {
                            j -= k;
                            k = k / 2;
                        }
                        j += k;
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

                    for (int i = 0, j = 0; i < n - 1; i++)
                    {
                        if (i < j && j < n)
                        {
                            auto temp = x[i];
                            x[i] = x[j];
                            x[j] = temp;
                        }
                        auto k = n / 2;
                        while (k < j && k > 0)
                        {
                            j -= k;
                            k = k / 2;
                        }
                        j += k;
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