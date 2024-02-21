#include <vector>
#include <cassert>

#include "fft.h"
#include "naive_complex.h"

namespace FFT
{
    using ComplexSpace::Complex;
    using FloatSpace::Float;
    using std::vector;

    /// @brief Naive Discrete Fourier Transform with O(n^2) complexity
    vector<Complex> naive_dft(const vector<Complex> &input)
    {
        const auto n = input.size();
        const vector<Complex> &x = input;
        vector<Complex> y(n);

        for (auto k = 0; k < n; k++)
        {
            Complex sum;
            for (auto j = 0; j < n; j++)
            {
                sum += x[j] * Complex::primitive_pow(n, j * k);
            }
            y[k] = sum;
        }

        return y;
    }

    /// @brief Naive Discrete Inverse Fourier Transform with O(n^2) complexity
    vector<Complex> naive_inverse_dft(const vector<Complex> &input)
    {
        const auto n = input.size();
        Float n_recip(1.0 / static_cast<FloatSpace::InnerFloat>(n));
        const vector<Complex> &y = input;
        vector<Complex> x(n);

        for (auto j = 0; j < n; j++)
        {
            Complex sum;
            for (auto k = 0; k < n; k++)
            {
                sum += y[k] * Complex::primitive_pow(n, j * k).conjugate();
            }
            sum.real *= n_recip;
            sum.imag *= n_recip;
            x[j] = sum;
        }

        return x;
    }

    bool size_is_power_of_2(size_t n)
    {
        return n && (!(n & (n - 1)));
    }

    size_t power_with_base_2(size_t n)
    {
        assert(size_is_power_of_2(n));
        auto power = 0;
        while (n != 1)
        {
            power += 1;
            n = n / 2;
        }
        return power;
    }
}