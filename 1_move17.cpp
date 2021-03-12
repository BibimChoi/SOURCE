#include <iostream>
#include <string>

// 생성자도 일종의 "setter" 입니다.
// 최선의 생성자를 만들어 봅시다.

template<typename T, typename U> struct PAIR
{
	T first;
	U second;

	// 아래 코드는 C++98 시절에는 최선의 코드 지만
	// C++11 부터는 move 지원이 안되는 코드
	//PAIR(const T& a, const U& b) : first(a), second(b) {}

	// C++11 의 move를 지원 하려면
	// 인자가  2개 => 4개의 생성자    인자가 3개 => 8개의 생성자가 필요 하다.
	// 인자가 많아 지면 직접 만들지 말고 "forwarding reference"가 최선이다.
//	PAIR(const T& a, const U& b) : first(a), second(b) {}
//	PAIR(T&& a,U&& b) : first(std::move(a)), second(std::move(b)) {}
//	PAIR(T&& a, const U& b) : first(std::move(a)), second(b) {}
//	PAIR(const T& a, U&& b) : first(a),            second(std::move(b)) {}

	// 아래 코드가 C++11이후 가장 널리 사용되는 생성자 모양입니다
	template<typename A, typename B>
	PAIR(A&& a, B&& b) : first(std::forward<A>(a)), second(std::forward<B>(b)) {}
	
};

int main()
{
	std::string s1 = "ABC";
	std::string s2 = "EFGH";
	PAIR<std::string, std::string> p1(s1, s2);
	PAIR<std::string, std::string> p2(std::move(s1), s2);
}
