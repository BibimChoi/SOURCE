#include <iostream>
#include <list>
#include <vector>

// 핵심 : sum() 만들기

// 컨테이너::value_type => 컨테이너가 저장하는 타입
// 반복자::value_type   => 반복자가 가리키는 요소의 타입

template<typename T> 
typename T::value_type sum(T first, T last)
{
	// T             : 반복자 타입
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

	int n = sum( c.begin(), c.end() );
	
	std::cout << n << std::endl;
}
