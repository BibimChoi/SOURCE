// 3_함수객체1
#include <iostream>

// 파이썬 해보신 분은 파이썬에서 함수객체가 있습니다.(callable object )
// class A :
//	  def __call__(self) : => C++의 operator()
//		print('A')

//a = A()
//a(); // 객체지만 함수처럼 사용


// 함수객체(function object, 또는 functor )
// () 연산자를 재정의 해서 함수 처럼 사용가능한 객체

// 왜 일반함수를 사용하지 함수객체를 사용하는가 ?
// 1. 상태를 가지는 함수
// 2. 특정 상황에서 함수객체가 일반 함수보다 빠르다. ==> 람다표현식의 특징과연결



struct Plus		// ===> Plus는 "구조체"입니다.
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	Plus p;		// p는 "함수가 아닌 객체" 입니다.

	int n = p(1, 2); // 마치 함수 처럼 사용합니다. - "함수객체"라고 합니다.
			// p.operator()(1,2) 의 원리 입니다.

	// a + b; // a가 사용자 정의 타입 이라면
			  // a.operator+(b)
	// a - b; // a.operator-(b)
	// a();   // a.operator()()
	// a(1,2);// a.operator()(1,2) 라는 함수를 찾게 됩니다.
}
