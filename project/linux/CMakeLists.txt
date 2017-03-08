cmake_minimum_required(VERSION 3.2)
project(math_cpp)

include_directories(
    ../../include
)
add_executable(
    gcd_lcm ../../sample/gcd_lcm/gcd_lcm.cpp
)
add_executable(
    fibnaci ../../sample/fibnaci/fibnaci.cpp
)
