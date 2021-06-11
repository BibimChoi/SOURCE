#include <iostream>
#include <algorithm>


// 마지막 인자로 값이 아닌 조건(함수)를 받아서 검색하는 버전
int* find_if(int* first, int* last, bool(*pred)(int) )
{
	while (first != last && pred(*first) == false )
		++first;

	return first;
}

// 조건자 (predicator)
// bool을 반환하는 함수로서, find_if 등의 함수에 전달되는 함수
bool foo(int n) { return n % 3 == 0;  }


int main()
{
	int x[10] = { 1,2,6,7,8,3,4,5,9, 10 };

	// "값"이 아닌 "조건(함수)"를 검색하는 코드
	int* p = find_if(x, x + 10, foo);

	std::cout << *p << std::endl; // 6

	int k;
	std::cin >> k;

	// 사용자가 입력한 k의 배수를 찾고 싶다면 ???
	int* p = find_if(x, x + 10, ??);
}
