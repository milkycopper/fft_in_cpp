#include <vector>

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
        auto n = input.size();
        const vector<Complex> &x = input;
        vector<Complex> y(n);

        for (auto k = 0; k < n; k++)
        {
            auto sum = Complex(0.0, 0.0);
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
        auto n = input.size();
        Float n_recip(1.0 / static_cast<FloatSpace::InnerFloat>(n));
        const vector<Complex> &y = input;
        vector<Complex> x(n);

        for (auto j = 0; j < n; j++)
        {
            auto sum = Complex(0.0, 0.0);
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
}