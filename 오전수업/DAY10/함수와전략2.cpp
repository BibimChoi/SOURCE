#include <iostream>
#include <algorithm>

int* find(int* first, int* last, int v)
{
	while (first != last && *first != v)
		++first;

	return first;
}

// 인자로 함수를 받는 버전
// 마지막 인자로 : bool (int) 모양의 함수를 보내야 한다.
int* find_if(int* first, int* last, bool(*f)(int) )
{
	while (first != last && f(*first) == false )
		++first;

	return first;
}

// 조건자 : bool을 반환하는 함수로서, find_if 같은 알고리즘에 전달하는 함수
bool foo(int n) { return n % 3 == 0; }

int main()
{
	int x[10] = { 1,2,6,7,8,3,4,5,9, 10 };

	int* p = find_if(x, x + 10, foo);

	std::cout << *p << std::endl;

	int k;
	std::cin >> k;

	// find_if 의 3번째 인자로 전달되는 조건자는 "반드시 인자라 한개" 있어야 한다.
	// 사용자가 입력한 k의 배수를 찾고 싶다면 ?? 어떻게 해야 할까 ?
	
}
