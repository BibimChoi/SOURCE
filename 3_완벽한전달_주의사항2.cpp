// 9_완벽한전달_주의사항
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg));
}
void foo() {}
void foo(int a) {}
void foo(int a, int b) {}

int main()
{
	// 함수를 직접 호출하면 ok
	foo();
	foo(10);

	// 그런데...
	chronometry(foo, 1, 2); // ?
}









