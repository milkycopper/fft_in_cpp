#include <vector>

#include "naive_complex.h"

namespace FFT
{
    using ComplexSpace::Complex;
    using std::vector;

    vector<Complex> naive_dft(const vector<Complex> &input);
}