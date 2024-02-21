#include <gtest/gtest.h>

#include "naive_dft.h"
#include "recursive_out_of_place_decimate_in_freq.h"
#include "cooley_tukey_fft.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}