#include <gtest/gtest.h>

#include "naive_float.h"

using namespace FloatSpace;

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Float, Size)
{
    Float a(0.1);
#ifdef FLOAT_32
#ifndef FLOAT_64
    ASSERT_EQ(sizeof(a), 4);
#endif
#endif

#ifdef FLOAT_64
#ifndef FLOAT_32
    ASSERT_EQ(sizeof(a), 8);
#endif
#endif
}

TEST(Float, Constructor)
{
    Float a(0.1);
    auto b = a;
    ASSERT_TRUE(a.abs_diff_eq(b));
    Float c = 0.2;
    ASSERT_TRUE(c.abs_diff_eq(b + 0.1));
}

TEST(Float, Arithmetic)
{
    Float a(0.1);
    auto b = a;
    b += 0.1;

    ASSERT_TRUE((a + b).abs_diff_eq(0.3));
    ASSERT_TRUE((a - b).abs_diff_eq(-0.1));
    ASSERT_TRUE((a * b).abs_diff_eq(0.02));
    ASSERT_TRUE((a / b).abs_diff_eq(0.5));

    auto c = a;
    c += b;
    ASSERT_TRUE(c.abs_diff_eq(0.3));

    c = a;
    c -= b;
    ASSERT_TRUE(c.abs_diff_eq(-0.1));

    c = a;
    c *= b;
    ASSERT_TRUE(c.abs_diff_eq(0.02));

    c = a;
    c /= b;
    ASSERT_TRUE(c.abs_diff_eq(0.5));

    ASSERT_TRUE((-a).abs_diff_eq(-0.1));
}

TEST(Float, Abs)
{
    ASSERT_TRUE(Float(0.3).abs().abs_diff_eq(0.3));
    ASSERT_TRUE(Float(-0.3).abs().abs_diff_eq(0.3));

    ASSERT_TRUE(Float(9.4).abs().abs_diff_eq(9.4));
    ASSERT_TRUE(Float(-9.4).abs().abs_diff_eq(9.4));

    ASSERT_TRUE((Float(-9.4).abs() + Float(-9.4)).abs_diff_eq(0.0));
}

TEST(Float, Compare)
{
    ASSERT_TRUE(Float(0.3) > 0.2);
    ASSERT_TRUE(Float(-0.3) < 0.2);

    ASSERT_TRUE(Float(0.3) >= 0.3);
    ASSERT_TRUE(Float(0.3) <= 0.3);

    ASSERT_TRUE(Float(0.3).max(Float(0.2)).abs_diff_eq(0.3));
    ASSERT_TRUE(Float(0.3).min(Float(0.2)).abs_diff_eq(0.2));
}

TEST(Float, Sqrt)
{
    ASSERT_TRUE(Float(2.0).sqrt().abs_diff_eq(1.414, 0.01));
    ASSERT_FALSE(Float(2.0).sqrt().abs_diff_eq(1.414));
    ASSERT_FALSE(Float(-2.0).sqrt().abs_diff_eq(1.414, 0.01));
}

TEST(Float, Atan)
{
    auto pi_frac_4 = Float::pi() / 4.0;
    ASSERT_TRUE(Float(1.0).atan().abs_diff_eq(pi_frac_4, 1e-4));
    ASSERT_TRUE(Float(-1.0).atan().abs_diff_eq(-pi_frac_4, 1e-4));

    auto pi_frac_6 = Float::pi() / 6.0;
    ASSERT_TRUE((Float(1.0) / Float(3.0).sqrt()).atan().abs_diff_eq(pi_frac_6, 1e-4));
    ASSERT_TRUE((Float(-1.0) / Float(3.0).sqrt()).atan().abs_diff_eq(-pi_frac_6, 1e-4));
}

TEST(Float, SinCos)
{
    auto pi_frac_6 = Float::pi() / 6.0;
    ASSERT_TRUE(Float(pi_frac_6).sin().abs_diff_eq(0.5, 1e-6));
    ASSERT_TRUE(Float(pi_frac_6 * 2.0).cos().abs_diff_eq(0.5, 1e-6));
    ASSERT_TRUE(Float(-pi_frac_6).sin().abs_diff_eq(-0.5, 1e-6));
    ASSERT_TRUE(Float(-pi_frac_6 * 2.0).cos().abs_diff_eq(0.5, 1e-6));
    ASSERT_TRUE(Float(-pi_frac_6 * 4.0).cos().abs_diff_eq(-0.5, 1e-6));
}
