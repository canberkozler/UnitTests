#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include "utils.hpp"
#include "DCalculator.hpp"
#include <stdexcept>
#include <cstdlib>

TEST_CASE("add works correctly", "[utils][add]")
{
    REQUIRE(add(2, 3) == 5);
    REQUIRE(add(-1, 1) == 0);
    REQUIRE(add(0, 0) == 0);
}

TEST_CASE("div_int works correctly", "[utils][div]")
{
    REQUIRE(div_int(10, 2) == 5);
    REQUIRE(div_int(9, 3) == 3);
}

TEST_CASE("div_int throws on divide by zero", "[utils][div][exception]")
{
    REQUIRE_THROWS_AS(div_int(10, 0), std::runtime_error);
}

TEST_CASE("is_even detects even and odd numbers", "[utils][bool]")
{
    REQUIRE(is_even(4));
    REQUIRE_FALSE(is_even(5));
}

TEST_CASE("div_double works with floating point", "[utils][double]")
{
    REQUIRE(Catch::Approx(div_double(1.0, 3.0)).epsilon(1e-6) == 0.333333);
    REQUIRE(div_double(10.0, 2.0) == 5.0);
}

TEST_CASE("create_ptr returns pointer or nullptr", "[utils][pointer]")
{
    int* p1 = create_ptr(true);
    int* p2 = create_ptr(false);

    REQUIRE(p1 != nullptr);
    REQUIRE(p2 == nullptr);
}

// for testing, uncomment the following test case and code in cmake file
// TEST_CASE("fatal_error causes abnormal termination", "[utils][fatal]")
// {
//     REQUIRE_THROWS_AS(fatal_error(), std::runtime_error);
// }

class DCalculatorFixture {
protected:
    DCalculator calc;
};

TEST_CASE_METHOD(DCalculatorFixture,
                 "DCalculator add works",
                 "[DCalculator]")
{
    REQUIRE(calc.add(2.3, 3.1) == Catch::Approx(5.4));
}

TEST_CASE_METHOD(DCalculatorFixture,
                 "DCalculator multiply works",
                 "[DCalculator]")
{
    REQUIRE(calc.multiply(2.0, 3.0) == Catch::Approx(6.0));
}