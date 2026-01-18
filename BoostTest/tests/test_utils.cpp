#define BOOST_TEST_MODULE UtilsTest
#include <boost/test/included/unit_test.hpp>
#include "utils.hpp"

BOOST_AUTO_TEST_CASE(AddWorks)
{
    BOOST_TEST(add(2,3) == 5);
    BOOST_TEST(add(-1,1) == 0);
}

BOOST_AUTO_TEST_CASE(DivideWorks)
{
    BOOST_TEST(div_int(10,2) == 5);
    BOOST_CHECK_THROW(div_int(10,0), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(IsEvenWorks)
{
    BOOST_TEST(is_even(4) == true);
    BOOST_TEST(is_even(5) == false);
}