#include <iostream>
#include <type_traits>

class Empty {};

/*
template<typename T, typename U > 
struct PAIR
{
	T first;
	U second;

	PAIR() = default;
	PAIR(const T& a, const T& b) : first(a), second(b) {}

	T& getFirst()  { return first; }
	U& getSecond() { return second; }
};
*/
template<typename T, typename U >
struct PAIR : public T
{
	U second;

	PAIR() = default;
	PAIR(const T& a, const T& b) : T(a), second(b) {}

	T& getFirst() { return *this; }
	U& getSecond() { return second; }
};


int main()
{
//	PAIR<int, int> p1;
//	std::cout << sizeof(p1) << std::endl; // 8

	PAIR<Empty, int> p2;
	std::cout << sizeof(p2) << std::endl;


}
