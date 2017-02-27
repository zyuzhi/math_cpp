// @author zyuzhi
#include <cstdint>

// zyuzhi
namespace zyuzhi
{
// zyuzhi.math
namespace math
{

template<typename T>
T gcd(T a, T b)
{
	T t;
	while (b > 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

template<typename T>
T lcm(T a, T b)
{
	return a / gcd(a, b) * b;
}

template<typename T>
T lcm(T a, T b, T c)
{
	return lcm(a, lcm(b, c));
}

template<typename T>
typename T::value_type lcm(const T &v)
{
	typedef typename T::value_type value_t;
	typedef typename T::const_iterator iterator_t;
	iterator_t i_begin = std::begin(v);
	iterator_t i_end = std::end(v);
	size_t size = i_end - i_begin;
	if (size < 2)
	{
		throw;
	}
	value_t value = lcm(*(i_begin++), *(i_begin++));
	for (; i_begin != i_end; ++i_begin)
	{
		value = lcm(value, *i_begin);
	}
	return value;
}

template<typename T, int Length>
T lcm(T (&arr)[Length])
{
	if (Length < 2)
	{
		throw;
	}
	T value = lcm(arr[0], arr[1]);
	for (int i = 2; i < Length; ++i)
	{
		value = lcm(value, arr[i]);
	}
	return value;
}

template<typename T, int Length>
T lcm(const T (&arr)[Length])
{
	if (Length < 2)
	{
		throw;
	}
	T value = lcm(arr[0], arr[1]);
	for (int i = 2; i < Length; ++i)
	{
		value = lcm(value, arr[i]);
	}
	return value;
}


// zyuzhi.math.mpl
namespace mpl
{
template<uint32_t value1, uint32_t value2>
struct gcd
{
	static const int value = gcd<value2, value1 % value2>::value;
};

template<uint32_t value1>
struct gcd<value1, 0>
{
	static const int value = value1;
};

template<uint32_t value1, uint32_t value2>
struct lcm
{
	static const int value = value1 / gcd<value1, value2>::value * value2;
};
}
}
}