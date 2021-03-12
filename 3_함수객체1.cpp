// 3_함수객체1
#include <iostream>

// 함수객체(Function Object, Functor 라도 합니다)   :파이썬 __call__

// () 연산자를 재정의 해서 함수 처럼 사용가능한 객체..

// 왜 ?? 일반 함수 대신 함수 객체를 사용하나요 ???
// 1. 상태를 가지는 함수
// 2. 특정 상황에서 일반 함수 보다 함수 객체가 빠르다. ==> 결국, 람다의핵심!!

struct Plus // ===> 분명 구조체 입니다.
{
	// operator():함수 이름입니다.
	int operator()(int a, int b)
	{
		return a + b;
	}
};
int main()
{
//	Plus p(1, 2);// 이 것은 Plus(1,2) 즉, 생성자 호출
//	p(1, 2);     // p.operator()(1, 2) 호출

	Plus p; // p는 함수가 아니라 "객체" 입니다.

	int n = p(1, 2); // 객체 p를 함수 처럼 사용합니다 => "함수객체"
			// p.operator()(1, 2) 의 원리로 실행됩니다.				

	// a + b; // a.operator+(b)  를 찾게 됩니다. (a가 사용자 정의 타입이면)
	// a - b; // a.operator-(b)
	// a();   // a.operator()() 
	// a(1,2);// a.operator()(1,2) 의 모양이 됩니다. 
}
