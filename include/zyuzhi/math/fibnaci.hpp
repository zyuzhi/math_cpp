// @author zyuzhi
#pragma once
#ifndef ZYUZHI_MATH_FITNACI_HPP
#define ZYUZHI_MATH_FITNACI_HPP

#include <cstdint>
#include <zyuzhi/math/macros.h>

MATH_NAMESPACE_BEGIN

uint32_t fibnaci(const uint32_t &n)
{
    return n <= 2 ? 1 : fibnaci(n - 1) + fibnaci(n - 2);
}

uint32_t fibnaci_noncursive(const uint32_t &val)
{
    if (val <= 2) {
        return 1;
    }
    uint32_t val1 = 1;
    uint32_t val2 = 1;

    for (uint32_t i = 3; i <= val; ++i) {
        uint32_t temp = val1;
        val1 = val2;
        val2 = val1 + temp;
    }
    return val2;
}

// zyuzhi.math.mpl
namespace mpl
{
template <uint32_t n>
struct fibnaci
{
    static const uint32_t value = fibnaci<n-1>::value + fibnaci<n-2>::value;
};

template <>
struct fibnaci<2>
{
    static const uint32_t value = 1;
};
template <>
struct fibnaci<1>
{
    static const uint32_t value = 1;
};
}

MATH_NAMESPACE_END
#endif
