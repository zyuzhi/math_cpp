// @author zyuzhi
#include <iostream>
#include <vector>
#include <zyuzhi/math/gcd_lcm.hpp>

int main()
{
	using namespace zyuzhi::math;
	// array
	int arr[3] = {35, 63, 7};
	std::cout << lcm(arr) << std::endl;

	// vector
	std::vector<int> v;
	v.push_back(35);
	v.push_back(63);
	v.push_back(7);
	std::cout << lcm(v) << std::endl;

	// meta template
	std::cout << mpl::lcm<mpl::lcm<35, 63>::value, 7>::value << std::endl;

	return 0;
}
