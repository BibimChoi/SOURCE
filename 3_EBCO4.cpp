#include <iostream>
#include <type_traits>

// 아래 코드가 boost 라이브러리 안에 있는 "cmpressed pair" 입니다.

class Empty {};

// 결국 PAIR는 2개의 부분 특수화 버전만 사용하게 됩니다
// 이경우에는 primary template 은 선언만 있으면 됩니다.
template<typename T, typename U, bool b = std::is_empty_v<T>  >
struct PAIR;


// 마지막 인자에 따라 구현을 다르게 하자.
template<typename T, typename U >
struct PAIR<T, U, false>
{
	T first;
	U second;

	PAIR() = default;
	PAIR(const T& a, const T& b) : first(a), second(b) {}

	T& getFirst()  { return first; }
	U& getSecond() { return second; }
};

template<typename T, typename U >
struct PAIR<T, U, true> : public T
{
	U second;

	PAIR() = default;
	PAIR(const T& a, const T& b) : T(a), second(b) {}

	T& getFirst() { return *this; }
	U& getSecond() { return second; }
};


int main()
{
	PAIR<int, int> p1;
	std::cout << sizeof(p1) << std::endl; // 8

	PAIR<Empty, int> p2;
	std::cout << sizeof(p2) << std::endl; // 4


}
