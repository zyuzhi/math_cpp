// @author zyuzhi
#include <iostream>
#include <zyuzhi/math/fibnaci.hpp>

int main()
{
    using namespace zyuzhi::math;
    std::cout << "fibnaci(40) " << mpl::fibnaci<40>::value << std::endl;
    std::cout << "fibnaci(40) " << fibnaci(40) << std::endl;
    std::cout << "fibnaci(40) " << fibnaci_noncursive(40) << std::endl;

    return 0;
}

