#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>  // C++20
#include <functional>
struct Point
{
	int x{ 0 };
	int y{ 0 };
};
int main()
{
	std::vector<Point> v;
	v.emplace_back(1, 2); // v.push_back( Point(1,2))
	v.emplace_back(2, 1);
	v.emplace_back(3, 5);

	// 정렬하고 싶다.
//	std::sort(v.begin(), v.end()); // Point 가 "<" 연산이 가능해야 한다.
	std::sort(v.begin(), v.end(), 
		[](const Point& p1, const Point& p2) {return p1.x < p2.x; }); // C++11

	// C++20 부터
	// 1. 반복자 대신 컨테이너 전달
	// 2. 어느 멤버로 비교할지 전달 가능 - "Projection" 이라는 개념.
	std::ranges::sort(v, std::less{}, &Point::x);
}
// g++ 소스.cpp -std=c++20




