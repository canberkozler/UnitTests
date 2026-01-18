#define BOOST_TEST_MODULE DCalculatorTest
#include <boost/test/included/unit_test.hpp>
#include "DCalculator.hpp"

BOOST_AUTO_TEST_CASE(AddWorks)
{
    DCalculator calc;
    BOOST_TEST(calc.add(2.5,3.5) == 6.0);
}

BOOST_AUTO_TEST_CASE(MultiplyWorks)
{
    DCalculator calc;
    BOOST_TEST(calc.multiply(2.0,3.0) == 6.0);
}