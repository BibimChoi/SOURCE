#include <iostream>
#include <algorithm>

// 3번(C#언어가 사용하는 방식)의 문제점
// 1. 인터페이스 기반이므로 valid가 가상함수 이다.(느리다.)
// 2. find_if 에는 IPredicator에서 파생된 객체만 보낼수 있다. 일반함수를 사용할수 없다.


// 조건자를 "템플릿" 으로 전달 받게 합니다.
template<typename Pred> 
int* find_if(int* first, int* last, Pred f) // 템플릿 이므로 어떠한 타입도 올수 있습니다
{											// 단, () 연산자로 호출 가능해야 합니다.
	while (first != last && f(*first) == false)
		++first;

	return first;
}
//--------------------------------
struct IsMod 
{
	int value;
public:
	IsMod(int n) : value(n) {}

	// 객체를 함수 처럼 ()로 호출가능하게 하기 위해서 ()연산자를 연산자 재정의 합니다.
	inline bool operator()(int n) { return n % value == 0; }
};
// IsMod f(6);
// f(10);	// 객체인 f를 함수 처럼 사용해도 됩니다.
//			// f.operator()(10)

bool foo(int n) { return n % 3 == 0; }


int main()
{
	int x[10] = { 1,2,6,7,8,3,4,5,9, 10 };

	int k;
	std::cin >> k;

	// 이제 아래처럼 조건자로, "일반함수", "객체" 모두 전달 가능합니다
	// 객체로 전달하는 것의 장점은 상태를 가지는 함수라는 점입니다.
	IsMod f(k);
	int* p1 = find_if(x, x + 10, f);
	int* p2 = find_if(x, x + 10, foo);

	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
}
