// 10_concept1
#include <iostream>
#include <type_traits>

// template : ��� Ÿ��

template<typename T> void foo(T a)
{
}

int main()
{
	int n = 10;
	foo(n);
}