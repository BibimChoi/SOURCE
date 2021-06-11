#include <iostream>
#include <algorithm>

// 3번 방식의 단점
// 1. 인터페이스 기반 이므로 valid() 함수는 가상함수 이다. 느리다.
// 2. find_if 에는 "조건자 객체"만 보낼수 있다. "일반함수로된 조건자"는 보낼수 없다.


// 일반 함수와 객체를 모두 사용가능하게 하기 위해 - 조건자는 "템플릿"으로 받는다.
// 조건자는 "함수와 함수객체 모두 가능하지만 단, ()연산자로 호출가능해야 한다."
// callable 타입이 되어야 한다.
template<typename Pred>
int* find_if(int* first, int* last, Pred pred)
{
	while (first != last && pred(*first) == false)
		++first;
	return first;
}
bool foo(int n) { return n % 3 == 0; }

//-----------------------
// find_if 에 보낼 조건자 객체를 만든다.
struct IsMod
{
	int value;
public:
	IsMod(int n) : value(n) {}

	inline bool operator()(int n) const { return n % value == 0; }
};

int main()
{
	int x[10] = { 1,2,6,7,8,3,4,5,9, 10 };

	int k;
	std::cin >> k;

	// 사용자가 입력한 k의 배수를 찾고 싶다면 ???
	IsMod pred(k);

	int* p = find_if(x, x + 10, pred);

	std::cout << *p << std::endl;
}
