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

    bool size_is_power_of_2(size_t n);
    size_t power_with_base_2(size_t n);

    namespace RecursiveMethods
    {
        namespace OutOfPlaceMethods
        {
            namespace DecimateInFreq
            {
                vector<Complex> fft(const vector<Complex> &input);
                vector<Complex> inverse_fft(const vector<Complex> &input);
            }
        }
    }

    namespace CircularMethods
    {
        namespace InplaceMethods
        {
            namespace CooleyTukey
            {
                void fft(vector<Complex> &input);
                void inverse_fft(vector<Complex> &input);
            }
        }
    }
}