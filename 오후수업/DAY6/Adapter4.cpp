#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
using namespace std;

// STL 은 어답터 패턴을 많이 사용합니다.
// 반복자 어답터 ( iterator adapter )
int main()
{
	list<int> ss = { 1,2,3,4,5 };

	auto p = ss.begin();

	++p;
	cout << *p << endl; // 2

	// reverse iterator adapter : ++ => --, -- =>++ 로 동작을 변경한 어답터

	// 반복자 p의 동작을 꺼꾸로 하도록하는 어답터
	// -- 연산 => ++
	// ++ 연산 => --
//	std::reverse_iterator< std::list<int>::iterator > ri(p); // 초기화 시 p-1 로 초기화

	auto ri = std::make_reverse_iterator(p); // 이코드가 위와 동일합니다.

	std::cout << *ri << std::endl; // 1
	--ri; // ++p가 됩니다
	std::cout << *ri << std::endl; // 2

}
