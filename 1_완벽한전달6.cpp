#include <iostream>
void foo(int a, int b, int c) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}

// 핵심. 완벽한 전달을 하려면
// 1. 인자를 받을때 "T&&" 를 사용
// 2. 인자를 다른곳에 보낼때는 "std::forward<T>(arg)"로 묶어서 전달
// 3. "가변인자 템플릿"을 사용해야 한다. - C++11

template<typename F, typename ... T> void chronometry(F f, T&& ... arg)
{
	f( std::forward<T>(arg)... ); 
}

int main()
{
	int n = 10;

	chronometry(foo, 10, 20, n); 
	chronometry(goo, n);  

	std::cout << n << std::endl;
}



