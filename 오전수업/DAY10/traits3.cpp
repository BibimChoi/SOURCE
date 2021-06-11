#include <iostream>
#include <list>
#include <vector>

template<typename T>
typename T::value_type sum(T first, T last)
{
	// T             : 반복자 입니다.
	// T::value_type : 반복자가 가리키는 타입

	// 그런데.. T가 진짜 포인터 라면 T::value 타입은 없습니다. 그래서 에러발생.. 
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
//	std::vector<int> c = { 1,2,3,4,5 };
//	std::list<int>   c = { 1,2,3,4,5 };

	int c[5] = { 1,2,3,4,5 }; // 이제, c 는 진짜 배열입니다.

	int n = sum(std::begin(c), std::end(c)); // container와 배열 모두 가능.
											// c가 배열일때 std::begin(c)는 c의 시작 주소..

	//int n = sum(c.begin(), c.end()); // 이렇게 하면 c가 container 인 경우만 되고
										// raw array 일때는 될수 없습니다.

	std::cout << n << std::endl;
}

