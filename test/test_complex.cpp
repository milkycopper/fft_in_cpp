#include <gtest/gtest.h>

#include "naive_complex.h"

using namespace ComplexSpace;

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Complex, Arithmetic)
{
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);

    ASSERT_TRUE((a + b).abs_diff_eq(Complex(4.0, 6.0)));
    ASSERT_TRUE((a - b).abs_diff_eq(Complex(-2.0, -2.0)));
    ASSERT_TRUE((a * b).abs_diff_eq(Complex(-5.0, 10.0)));
    ASSERT_TRUE((a / b).abs_diff_eq(Complex(0.44, 0.08)));

    auto c = a;
    c += b;
    ASSERT_TRUE(c.abs_diff_eq(Complex(4.0, 6.0)));

    c = a;
    c -= b;
    ASSERT_TRUE(c.abs_diff_eq(Complex(-2.0, -2.0)));

    c = a;
    c *= b;
    ASSERT_TRUE(c.abs_diff_eq(Complex(-5.0, 10.0)));

    c = a;
    c /= b;
    ASSERT_TRUE(c.abs_diff_eq(Complex(0.44, 0.08)));

    ASSERT_TRUE((-a).abs_diff_eq(Complex(-1.0, -2.0)));
    ASSERT_FALSE((-a).abs_diff_eq(Complex(-1.0, -2.1)));
    ASSERT_TRUE((-a).abs_diff_eq(Complex(-1.0, -2.01), 0.1));
    ASSERT_FALSE((-a).abs_diff_eq(Complex(-1.2, -2.01), 0.1));
}

TEST(Complex, NormArg)
{
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);

    ASSERT_TRUE(a.norm().abs_diff_eq(Float(5.0).sqrt(), 1e-10));
    ASSERT_TRUE(b.norm().abs_diff_eq(5.0, 1e-10));

    ASSERT_TRUE(Complex(1.0, 1.0).norm().abs_diff_eq(Float(2.0).sqrt(), 1e-10));
    auto pi_frac_4 = 3.14149 / 4.0;
    ASSERT_TRUE(Complex(1.0, 1.0).arg().abs_diff_eq(pi_frac_4, 1e-4));
}
