#include <iostream>
#include <functional>
using namespace std::placeholders; // _1, _2, _3 등이 이 namespace 에 있습니다.

void foo(int a, int b, int c, int d)
{
	printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4); // 4항 함수

	// C++11부터 지원되는 std::bind : M항함수 => N항함수로 변경하는 도구(단, M > N )

	// 사용법 : std::bind( M항 함수 주소, M개의 갯수)


	std::bind(&foo, 5, 2, _1, _2) (10, 7);	// foo( 5, 2, 10, 7)
	//|<- 여기까지가 새로운 함수 ->|			// 결국 4항함수 => 2항 함수로 변경한것

	
}


