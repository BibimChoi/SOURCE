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
	//	  => 이런 작업을 여러번 해야 한다면???!!

	// 2. list 안에 요소를 2배로 하는 멤버 함수 제공
	//	  => s.TwiceAllElement()
	//	  => vector 나 deque 도 필요하다면...

	// 3. 방문자 패턴을 사용한다.

	TwiceVisitor<int> tv; // 모든 요소를 2배로 하는 방문자
	s.Accept(&tv);        // 모든 컨테이너는 방문자를 받아 들여야 한다.

	ShowVisitor<int> sv;
	s.Accept(&sv);
}









