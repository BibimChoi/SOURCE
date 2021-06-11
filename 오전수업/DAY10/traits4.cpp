#include <iostream>
#include <list>
#include <vector>

// C++에서 반복자의 형태별 분류
// 1. 객체(클래스로 만들어진)로 된 반복자
// 2. Raw Pointer( int* 등)

// 위 2가지 차이점 때문에 아래의 sum()같은 함수 만들기가 어렵습니다.

// 이 문제를 해결하는 "간접층"
template<typename T> struct iterator_traits
{
	typedef typename T::value_type value_type;
};

// T가 RawPointer 라면 아래 코드를 사용해달라는 "template partial specialization" 문법
template<typename T> struct iterator_traits<T*>
{
	typedef T value_type;
};


template<typename T>
typename iterator_traits<T>::value_type  sum(T first, T last)
{
	// typename T::value_type s = 0; // T 가 객체형 반복자 인경우만 가능

	typename iterator_traits<T>::value_type s = 0; // T가 객체형 반복자 또는 "Raw Pointer" 라도 동작



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

	int n = sum( std::begin(c), std::end(c)) ; 
	
	std::cout << n << std::endl;
}

