#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "utils.hpp"
#include "DCalculator.hpp"

TEST_CASE("add function") {
    CHECK(add(2, 3) == 5);
    CHECK(add(-1, 1) == 0);
}

TEST_CASE("div_int function") {
    CHECK_THROWS_AS(div_int(10, 0), std::runtime_error);
    CHECK_NOTHROW(div_int(10, 2));
}

TEST_CASE("is_even function") {
    CHECK(is_even(4));
    CHECK_FALSE(is_even(5));
}

TEST_CASE("div_double function") {
    CHECK(doctest::Approx(div_double(1.0, 3.0)) == 0.333333);
}

TEST_CASE("create_ptr function") {
    CHECK(create_ptr(true) != nullptr);
    CHECK(create_ptr(false) == nullptr);
}

TEST_CASE("DCalculator class") {
    DCalculator calc;

    SUBCASE("add") {
        CHECK(calc.add(2.3, 3.1) == doctest::Approx(5.4));
    }

    SUBCASE("multiply") {
        CHECK(calc.multiply(2.0, 3.0) == 6.0);
    }
}

// Fatal error test: sadece UNIT_TEST define edilirse throw
#ifdef UNIT_TEST
TEST_CASE("fatal_error") {
    CHECK_THROWS_AS(fatal_error(), std::runtime_error);
}
#endif