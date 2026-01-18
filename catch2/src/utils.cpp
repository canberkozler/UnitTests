#include "utils.hpp"
#include <stdexcept>

int add(int a, int b)
{
    return a + b;
}

int div_int(int a, int b)
{
    if (b == 0)
        throw std::runtime_error("divide by zero");
    return a / b;
}

bool is_even(int x)
{
    return (x % 2) == 0;
}

double div_double(double a, double b)
{
    return a / b;
}

int* create_ptr(bool bval)
{
    static int x = 5;
    return bval ? &x : nullptr;
}

void fatal_error()
{
#ifdef UNIT_TEST
    throw std::runtime_error("fatal error");
#else
    std::abort();
#endif
}