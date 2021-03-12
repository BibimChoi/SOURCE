#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0;  }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	// v에서 3을 찾고 싶다.
	auto p1 = std::find(begin(v), end(v), 3);  // "값 검색"
	std::cout << *p1 << std::endl; // 3

	// v에서 1번째 나오는 3의 배수를 찾고 싶다.? => "조건 검색"

	//auto p2 = std::find_if(begin(v), end(v), foo ); // C++98 스타일

	// C++11 : 함수 이름(주소)을 전달해야 하는 곳에 람다 표현식을 사용하자!
	auto p2 = std::find_if(begin(v), end(v), [](int n) { return n % 3 == 0;}); // C++11 스타일
	
	std::cout << *p2 << std::endl; // 6
}




