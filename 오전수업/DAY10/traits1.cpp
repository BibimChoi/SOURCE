#include <iostream>
#include <list>
#include <vector>

/*
void print_first_element(std::vector<int>& v)
{
	int n = v.front();

	std::cout << n << std::endl;
}
*/

/*
template<typename T>
void print_first_element(std::vector<T>& v)
{
	T n = v.front();

	std::cout << n << std::endl;
}
*/

template<typename T>
void print_first_element(T& v)
{
	// T : list<double>
	// T::value_type  ==> list<double>::value_type ==> double 

	// ? : double 을 사용하고 싶습니다.

	// T::value_type : 컴파일러가 value_type을 static 멤버 데이타 등으로 생각하게 됩니다.
	// typename T::value_type : static 멤버 데이타가 아니라. 타입의 이름으로 해석해 달라

	typename T::value_type n = v.front();

	std::cout << n << std::endl;
}

int main()
{
//	std::vector<int>    c = { 1,2,3,4,5 };
//	std::vector<double> c = { 1,2,3,4,5 };
	std::list<double> c = { 1,2,3,4,5 };

	print_first_element(c);
}
/*
// C++ 코딩 규칙
// 템플릿 기반의 컨테이너를 설계 할때는 컨테이너가 저장하는 요소의 타입을 
// 알려주는 value_type을 꼭 넣으세요..
template<typename T> class list
{
public:
	typedef T value_type;
};

list<int> s;
list<int>::value_type n; // n의 타입은 ? => int
*/


