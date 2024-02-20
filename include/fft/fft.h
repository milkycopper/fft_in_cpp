#include <vector>

#include "naive_complex.h"

namespace FFT
{
    using ComplexSpace::Complex;
    using std::vector;

    /// @brief Naive Discrete Fourier Transform with O(n^2) complexity
    vector<Complex> naive_dft(const vector<Complex> &input);
    /// @brief Naive Discrete Inverse Fourier Transform with O(n^2) complexity
    vector<Complex> naive_inverse_dft(const vector<Complex> &input);
}