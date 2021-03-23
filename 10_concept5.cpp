// 10_concept5
#include <iostream>
#include <type_traits>

template<typename T> void foo(T a)
{
	std::cout << "1" << std::endl;
}
template<typename T> void foo(T a)
{
	std::cout << "2" << std::endl;
}
int main()
{
	foo(3);
}