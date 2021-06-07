#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
using namespace std;
// STL 은 어답터 패턴을 많이 사용합니다.
// 반복자 어답터
int main()
{
	list<int> ss = { 1,2,3,4,5 };

	auto p = ss.begin();

	++p;
	cout << *p << endl; // 2

	// ++, -- 동작을 꺼꾸로 하는 반복자가 필요하다면
	// 반복자 adapter를 사용하면 됩니다. (객체 p에 대한 동작을 거꾸로 하는 객체어답터입니다)
//	std::reverse_iterator<std::list<int>::iterator> ri(p); // ri는 ++ => -- 로 변경
								 //      -- => ++ 로 변경하는 어답터 입니다.
								 // 단, 초기화시 ri 는 p-1로 초기화 됩니다

	auto ri = std::make_reverse_iterator(p); // 이렇게 하면 위와 동일합니다.

	std::cout << *ri << std::endl; // 1
	--ri; // ++p 로 동작 합니다.
	std::cout << *ri << std::endl; // 2

}







