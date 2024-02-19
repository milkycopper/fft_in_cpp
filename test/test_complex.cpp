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
    auto pi_frac_4 = Float::pi() / 4.0;
    ASSERT_TRUE(Complex(1.0, 1.0).arg().abs_diff_eq(pi_frac_4, 1e-4));
}

TEST(Complex, FromAngleNorm)
{
    auto angle = Float::pi() / 4.0;
    ASSERT_TRUE(Complex::from_norm_angle(1.414, angle).abs_diff_eq(Complex(1.0, 1.0), 0.001));
    ASSERT_TRUE(Complex::from_angle(angle).abs_diff_eq(Complex(0.707, 0.707), 0.01));
}

TEST(Complex, Primitive)
{

    ASSERT_TRUE(Complex::primitive(8).abs_diff_eq(Complex(1.0, -1.0) / Complex(Float(2.0).sqrt(), 0.0), 1e-8));
    ASSERT_TRUE(Complex::primitive_pow(8, 9).abs_diff_eq(Complex(1.0, -1.0) / Complex(Float(2.0).sqrt(), 0.0), 1e-8));

    ASSERT_TRUE(Complex::primitive(4).abs_diff_eq(Complex(0.0, -1.0), 1e-8));
    ASSERT_TRUE(Complex::primitive_pow(4, 5).abs_diff_eq(Complex(0.0, -1.0), 1e-8));
}
