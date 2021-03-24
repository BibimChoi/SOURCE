// cafe.naver.com/cppmaster 에서 "DAY4.zip" 받으시면 됩니다

// 0_unevaluated1.cpp
#include <iostream>

// 핵심 
// 평가되지 않은 표현식(unevaluated expression)

int foo(int a, int b); // { return 0; }

int main()
{
	int a = 0;

	int n1 = sizeof(a);		// 4
	int n2 = sizeof(int);	// 4
	int n3 = sizeof(&foo);	// 함수 주소의 크기, 4 ( 32bit )
//	int n4 = sizeof(foo);	// 함수 의 크기 - error

	// sizeof(함수호출식) : 함수호출의 결과로 나오는 타입의 크기
	int n5 = sizeof( foo(1,2) );	// 4

	// 평가되지 않은 표현식(unevaluated expression)
	// 어떤 표현식이 "실행"되지는 않고 "컴파일시간"에만 사용되는 것
}








