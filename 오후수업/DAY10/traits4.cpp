#include <iostream>
#include <list>
#include <vector>

// 객체형 반복자와 Raw Pointer 의 차이점을 해결하기 위한 간접층(중간층, level of indirection)

template<typename T>
struct iterator_traits
{
	typedef typename T::value_type value_type;
};

// T가 Raw Pointer 일때 다른 구현을 제공하기 위한 "template partial specialization(부분특수화)"문법
template<typename T>
struct iterator_traits<T*>
{
	typedef T value_type;
};

template<typename T>
typename iterator_traits<T>::value_type sum(T first, T last)
{
	// T 가 객체형 반복자라면 value_type이 있습니다.
	// T 가 raw pointer 라면 아래 코드는 에러입니다.
	
	//typename T::value_type s = 0;

	typename iterator_traits<T>::value_type s = 0;


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

	int n = sum(std::begin(c), std::end(c)); 


	std::cout << n << std::endl;
}
