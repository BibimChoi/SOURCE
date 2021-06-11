// 함수객체를 받을때 어떤 방법이 최선일까요 ?

#include <iostream>
#include <functional>

// 1. call by value : 대부분의 함수객체는 empty 인경우가 많습니다. 1byte이므로 크지 않습니다.
// STL 표준 find_if()  가 이 방식 입니다.
// 단, 전달되는 함수객체가 큰 경우 오버헤드가 있습니다.
// template<typename Pred> void foo(T f) {}

// 2. call by non-const reference
// 임시객체를 받을수 없다.
// template<typename Pred> void foo(T& f) {}

// 3. call by const reference
// 임시객체도 받을수 있다.
// 단, () 연산자가 const 함수 이어야 한다. - mutable lambda는 ()연산자가 비상수 함수 이다.
//										받을수 없다.
// template<typename Pred> void foo(const T& f) { int n = f(1, 2);  }

// 4. forwarding reference(universal reference ) - 가장 무난하다!!
// 결론 : C++11 이전 => call by value 
//              이후 => call by universal reference 
template<typename Pred> void foo(T&& f) { int n = f(1, 2); }

int main()
{
	std::modulus<int> p; // STL 안에 있는 함수 객체(callable 타입) % 연산
	int n = p(10, 3); // 10 % 3 => 1
	foo(p);
	foo(std::modulus<int>()); // 임시객체는 non-const reference로는 받을수 없습니다

	foo([](int a, int b) mutable { return a + b; });
}
