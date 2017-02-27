// @author zyuzhi
#include <iostream>
#include <vector>
#include <zyuzhi/math/gcd_lcm.hpp>

int main()
{
    using namespace zyuzhi::math;
    int arr[3] = {35, 63, 7};
    std::vector<int> v;
    for (int i = 0; i < 3; ++i) {
        v.push_back(arr[i]);
    }
    // array lcm
    std::cout << "lcm(35, 63, 7) = " << lcm(arr) << std::endl;

    // vector lcm
    std::cout << "lcm(35, 63, 7) = " << lcm(v) << std::endl;

    // meta template lcm
    std::cout << "lcm(35, 63, 7) = " << mpl::lcm<mpl::lcm<35, 63>::value, 7>::value << std::endl;

    // array gcd
    std::cout << "gcd(35, 63, 7) = " << gcd(arr) << std::endl;

    // vector gcd
    std::cout << "gcd(35, 63, 7) = " << gcd(v) << std::endl;

    // meta template gcd
    std::cout << "gcd(35, 63, 7) = " << mpl::gcd<mpl::gcd<35, 63>::value, 7>::value << std::endl;

    return 0;
}
