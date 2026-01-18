#include "test.hpp"
#include "utils.hpp"
#include <stdexcept>
#include "DCalculator.hpp"

TEST(MathTest, AddWorks)
{
    EXPECT_EQ(add(2, 3), 5);
}

TEST(MathTest, DivideWorks)
{
    EXPECT_EQ(div_int(10, 2), 5); // if EXPECT fails, test continues
    ASSERT_EQ(div_int(10, 2), 5); // if ASSERT fails, test stops here
}

TEST(MathTest, DivideByZeroThrows)
{
    EXPECT_THROW(div_int(10, 0), std::runtime_error);
    EXPECT_NO_THROW(div_int(10, 2)); // Custom helper to check no exception is thrown
}

TEST(BooleanTest, TrueFalse)
{
    EXPECT_TRUE(is_even(4));
    EXPECT_FALSE(is_even(5));
}

TEST(DivTest, ThrowsWithCorrectMessage)
{
    try {
        div_int(10, 0);
        FAIL() << "Exception bekleniyordu";
    }
    catch (const std::runtime_error& e) {
        EXPECT_STREQ(e.what(), "divide by zero");
    }
}

TEST(FloatTest, Near)
{
    EXPECT_NEAR(div_double(1.0, 3.0), 0.333333, 1e-6);
}

TEST(PointerTest, NullCheck)
{
    EXPECT_NE(create_ptr(true), nullptr);
    EXPECT_EQ(create_ptr(false), nullptr);
}

TEST(RangeTest, ValueInRange)
{
    int x = add(3, 4);
    EXPECT_GT(x, 5);  // greater than
    EXPECT_LT(x, 10); // less than
    EXPECT_GE(x, 7);  // greater than or equal
    EXPECT_LE(x, 7);  // less than or equal
}

TEST(DeathTest, Abort)
{
    EXPECT_DEATH(fatal_error(), "");
}

TEST_P(AddParamTest, WorksForManyValues)
{
    auto [a, b, result] = GetParam();
    EXPECT_EQ(add(a, b), result);
}

INSTANTIATE_TEST_SUITE_P(
    AddCases,
    AddParamTest,
    ::testing::Values(
        std::make_tuple(1, 2, 3),
        std::make_tuple(-1, 1, 0),
        std::make_tuple(0, 0, 0)
    )
);

TEST(CalculatorTest, AddWorks)
{
    DCalculator calc;
    EXPECT_DOUBLE_EQ(calc.add(2.3, 3.1), 5.4);
    /* or use EXPECT_NEAR for floating point comparisons:
        EXPECT_NEAR(calc2.add(2.3, 3.1), 5.4, 1e-9);
    */
}

TEST(CalculatorTest, MultiplyWorks)
{
    DCalculator calc;
    EXPECT_DOUBLE_EQ(calc.multiply(2.0, 3.0), 6.0);
}

TEST_F(CalculatorTest2, AddWorks2)
{
    EXPECT_DOUBLE_EQ(calc2.add(2.3, 3.1), 5.4);
}

TEST_F(CalculatorTest2, MultiplyWorks2)
{
    EXPECT_DOUBLE_EQ(calc2.multiply(2.0, 3.0), 6.0);
}