#include <iostream>
#include <type_traits>

// 아래 코드가 boost 라이브러리 안에 있는 "cmpressed pair" 입니다.

class Empty {};



template<typename T, typename U >
struct PAIR
{
	// attribute : C++11 에서 추가된 문법. 컴파일러에게 지시하는 것
	//			 [[ 명령어  ]]
	// C++20 에서 추가된 "no_unique_address" 라는 attribute 
	[[no_unique_address]] T first;
	[[no_unique_address]] U second;

	PAIR() = default;
	PAIR(const T& a, const T& b) : first(a), second(b) {}

	T& getFirst() { return first; }
	U& getSecond() { return second; }
};





int main()
{
	PAIR<int, int> p1;
	std::cout << sizeof(p1) << std::endl; // 8

	PAIR<Empty, int> p2;
	std::cout << sizeof(p2) << std::endl; // 4


}
