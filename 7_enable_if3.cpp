#include <iostream>
#include <type_traits>

template<typename T>
typename std::enable_if< std::is_integral_v<T>, T>::type 
gcd(T a, T b)
{
	//static_assert(std::is_integral_v<T>, "error, T is no integer");

	return 0;
}

double gcd(double, double) { std::cout << "double" << std::endl; return 0; }

int main()
{
	gcd(6, 9);

	gcd(3.1, 5.4);
	gcd(3.1f, 5.4f); 
}
