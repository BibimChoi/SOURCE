#include <iostream>
void foo(int a, int b, int c) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}

// �ٽ�. �Ϻ��� ������ �Ϸ���
// 1. ���ڸ� ������ "T&&" �� ���
// 2. ���ڸ� �ٸ����� �������� "std::forward<T>(arg)"�� ��� ����
// 3. "�������� ���ø�"�� ����ؾ� �Ѵ�. - C++11

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



