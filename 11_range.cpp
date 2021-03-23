// 11_range
#include <iostream>
#include <vector>
#include <ranges> // C++20 헤더

// C++20 에는 RANGE 라는 새로운 형태의 STL 이 등장합니다.
int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9 };

	auto r = v | std::ranges::views::filter([](int a) { return a % 2 == 0; })
			   | std::ranges::views::take(3);

	for (auto n : r)
		std::cout << n << std::endl;

		   
}