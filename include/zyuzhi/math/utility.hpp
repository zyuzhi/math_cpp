// @author zyuzhi
#pragma once
#ifndef ZYUZHI_MATH_UTILITY_HPP
#define ZYUZHI_MATH_UTILITY_HPP
#include <zyuzhi/math/macros.h>
#include <zyuzhi/math/function_traits.hpp>
#include <vector>

MATH_NAMESPACE_BEGIN
namespace utility
{
template<typename Container, typename Function>
typename function_traits<Function>::result_type aggregate(const Container &v, const Function& func)
{
    typedef typename function_traits<Function>::result_type result_type;
    result_type value;
    auto it = std::begin(v);
    auto it_end = std::end(v);
    auto first = *it;
    ++it;
    auto second = *it;
    ++it;
    for (; it != it_end; ++it)
    {
        value = func(*it, value);
    }
    return value;
}
}
MATH_NAMESPACE_END
#endif
