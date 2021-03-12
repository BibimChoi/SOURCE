#include <iostream>
#include <vector>
#include <algorithm>
bool foo(int n) { return n % 3 == 0;  }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	// v에서 3을 찾고 싶다.
	auto p1 = std::find(begin(v), end(v), 3); // "값" 검색

	std::cout << *p1 << std::endl; // 3




	// v에서 1번째 나오는 3의 배수를 찾고 싶다.?  ==> "조건 검색"

	//auto p2 = std::find_if(begin(v), end(v), 함수);
	//auto p2 = std::find_if(begin(v), end(v), foo);

	// C++11 부터는 "함수 대신 람다표현식 사용"
	auto p2 = std::find_if(begin(v), end(v), [](int n) { return n % 3 == 0;});


	std::cout << *p2 << std::endl; // 6
}
// 람다표현식을 정확히 이해 하려면
// C++98 시절의 기술인 "함수객체"를 반드시 알아야 합니다.






