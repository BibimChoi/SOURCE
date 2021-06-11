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
	// ? 채워 보세요.( auto 도 가능하지만, auto 말고 정확한 타입으로, decltype도 제외, 
	//					즉, C++11 제외)

	// T : list<double>
	
	// T::value_type => list<double>::value_type => double

	// T::value_type          : value_type 이 static 멤버라고 컴파일러가 생각
	// typename T::value_type : value_type 이 typedef 되어있는 타입으로 생각해 달라.

	// 아래 코드가 컨테이너 T가 저장하는 타입을 꺼내는 코드 입니다.
	typename T::value_type  n = v.front();

	std::cout << n << std::endl;
}

int main()
{
//	std::vector<int>    c = { 1,2,3,4,5 };
//	std::vector<double> c = { 1,2,3,4,5 };
	std::list<double>   c = { 1,2,3,4,5 };

	print_first_element(c);
}

// 템플릿으로 컨테이너 만들때 규칙
// 자신이 저장하는 타입을 반드시 외부에 알려야 한다.
/*
template<typename T> class list
{
public:
	typedef T value_type;  // C++에서 꼭 지켜야 하는 규칙입니다.(문법은 아니지만 코딩관례)
};

list<int> s;
list<int>::value_type n; // 여기서 n의 타입은 ? => int 입니다.
*/
