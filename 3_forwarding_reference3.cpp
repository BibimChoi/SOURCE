#include "cppmaster.h"

template<typename T> void foo(T&& arg)
{
	// __FUNCTION__ : 함수의 이름을 담고 있는 매크로, C++ 표준
	std::cout << __FUNCTION__ << std::endl;
}
int main()
{
	int n = 10;

	foo(n);  // T=int&    T&&=int& && => int& 
	foo(10); // T=int     T&&=int&&

	const int c = 10;
	foo(c); 
}




