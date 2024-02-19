#include <gtest/gtest.h>

#include "naive_float.h"

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
