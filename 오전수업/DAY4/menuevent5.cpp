#include <iostream>
#include <functional>		// 이 헤더에 std::bind 가 있습니다.
using namespace std::placeholders; // _1, _2 가 이 안에 있습니다

void foo(int a, int b, int c, int d)
{
	printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4); // 4항 함수

	// C++의 bind : M항함수를 N항(단, N < M) 으로 변경하는 도구
	
	// std::bind( M항 함수, M개의인자 )

	std::bind(&foo, 3, 6, _1, _2)  (5, 10);		// foo(3,6,5,10) 과 동일
	//|<- 이부분의 최종결과는 함수->|				// 결국, 4항 함수 => 2항 함수로 변경

	std::bind(&foo, 1, 2, 3, 4)(); // 4항 => 0항 함수로 변경해서 호출한것

	std::bind(&foo, _2, _3, 9, _1 )(7, 3, 1);  // foo(3, 1, 9, 7) 나오도록 ? 채워 보세요
}








