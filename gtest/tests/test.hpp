#pragma once

#include <gtest/gtest.h>
#include <tuple>
#include "DCalculator.hpp"

class AddParamTest : public ::testing::TestWithParam<std::tuple<int,int,int>> {};

class CalculatorTest2 : public ::testing::Test {
protected:
    DCalculator calc2;   // test fixture member variable
    // newly created before each test
};