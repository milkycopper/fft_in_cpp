#include <gtest/gtest.h>

#include "complex64.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(complex, complex64_add)
{
    Complex64 a(1.0, 2.0);
    Complex64 b(3.0, 4.0);

    auto sum = a + b;
    ASSERT_TRUE(sum.abs_diff_eq(Complex64(4.0, 6.0)));
}
