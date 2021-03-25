// 5_PAIR2
#include <iostream>
#include <type_traits>
#include <string>

template<typename T, typename U> struct PAIR
{
	T first;
	U second;

	template<typename A, 
		     typename B,
			 typename = std::enable_if_t< std::is_same_v<A, T> && std::is_same_v<B, U> >>
	PAIR(A&& a, B&& b) : first(std::forward<A>(a)), second(std::forward<B>(b))
	{
	}
};

int main()
{
	std::string s1 = "AA";
	std::string s2 = "BBBB";

	PAIR<std::string, std::string> p1(s1, s2);
	PAIR<std::string, std::string> p2(s1, std::move(s2));

	PAIR<int*, int*> p3(1, 2);
}

