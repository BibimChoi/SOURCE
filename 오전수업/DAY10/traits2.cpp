#include <iostream>
#include <list>
#include <vector>

// 반복자 구간을 받아서 합을 반환하는 함수

template<typename T> 
typename T::value_type sum(T first, T last)
{
	// T             : 반복자 입니다.
	// T::value_type : 반복자가 가리키는 타입
	typename T::value_type s = 0;

	while (first != last)
	{
		s = s + *first;
		++first;
	}
	return s;
}

int main()
{
	std::vector<int> c = { 1,2,3,4,5 };

	int n = sum( c.begin(), c.end() ); // 만들어 봅시다.
	
	std::cout << n << std::endl;
}
