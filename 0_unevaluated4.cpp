#include <iostream>

class Test 
{
public:
//	void resize() {}
};
// 핵심 : SFINAE 개념을 사용해서 "조건을 만족하지 않으면 실패" 하는 템플릿 설계
// 조건 : 타입안에 resize 가 있는가 ??
// 타입을 받아야 하므로 템플릿으로 만든다.
template<typename T> int  check( decltype( T().resize() )* p  );
template<typename T> char check(...);

int main()
{
	int n = sizeof( check<Test>(0) );

	std::cout << n << std::endl;
}



