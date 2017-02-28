// @author zyuzhi
#pragma once
#ifndef ZYUZHI_MATH_FUNCTIONTRAITS_HPP
#define ZYUZHI_MATH_FUNCTIONTRAITS_HPP
#include <zyuzhi/math/macros.h>

MATH_NAMESPACE_BEGIN
template <typename T>
struct function_traits
    : public function_traits<decltype(&T::operator())>
{};

template <typename ClassType, typename ReturnType, typename Arg1>
struct function_traits<ReturnType(ClassType::*)(Arg1) const>
{
    typedef ReturnType result_type;
    typedef ClassType class_type;
    typedef Arg1 arg1_type;
};

template <typename ClassType, typename ReturnType, typename Arg1, typename Arg2>
struct function_traits<ReturnType(ClassType::*)(Arg1, Arg2) const>
{
    typedef ReturnType result_type;
    typedef ClassType class_type;
    typedef Arg1 arg1_type;
    typedef Arg2 arg2_type;
};
MATH_NAMESPACE_END
#endif
