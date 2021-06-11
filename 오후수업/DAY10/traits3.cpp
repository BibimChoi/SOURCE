#include <iostream>
#include <list>
#include <vector>

template<typename T>
typename T::value_type sum(T first, T last)
{
	// T 가 객체형 반복자라면 value_type이 있습니다.
	// T 가 raw pointer 라면 아래 코드는 에러입니다.
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

	int c[5] = { 1,2,3,4,5 };

	// raw array 도 컨테이너 입니다.
	// raw pointer 도 반복자의 일종입니다(++로 이동할수 있고, * 할수 있으므로)

//	int n = sum(c.begin(), c.end());			// c가 raw array 라면  에러

	int n = sum(std::begin(c), std::end(c) ); // c가 배열이라도 ok. C++11 에서 권장
											// std::begin(c) 에서 c가 배열이면
											// 반환값은 배열의 주소(raw pointer)


	std::cout << n << std::endl;
}
