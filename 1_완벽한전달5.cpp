#include <iostream>
void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}

/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f( static_cast<int&>(arg) ); // �ʿ� ���� ĳ���� ������ �־ �˴ϴ�.
								 // �ᱹ, �����Ͻ� ���ŵ˴ϴ�.
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/
// T&& �� ����ϸ� int&, int&& �� �Լ��� �ڵ������Ҽ� �ִ�.

template<typename F, typename T> void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 10;

	chronometry(foo, 10);
	chronometry(goo, n);

	std::cout << n << std::endl;
}



