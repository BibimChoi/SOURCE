#include <iostream>
#include <list>
#include <vector>

// 반복자 : 복합객체의 모든 요소를 동일한 방식으로 열거
// 방문자 : 복합객체의 모든 요소를 동일한 방식으로 연산수행
// visitor 패턴

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.

	// 1. 모든 요소를 차례대로 꺼낸후 2배로 변경해서 다시 넣는다.

	// 2. list 안에 요소를 2배로 하는 멤버 함수 제공
	//    s.TwiceAllElement()
	//	  vector나 deque 같은 컨테이너도 필요 할수 있다.!!

	// 3. 방문자 패턴을 사용한다.

	TwiceVisitor<int> tv; // 복합객체에 들어가서 모든 요소를 2배로 하는 방문자
	s.Accept(&tv);        // 복합객체는 방문자의 방문을 허락 해야 합니다.
							// 그런데, STL 에는 Accept가 없습니다.(방문자 패턴 사용안함)
							// Accept를 추가해 봅시다.
}





