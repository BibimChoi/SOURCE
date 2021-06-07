#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;

// GoF 디자인 패턴책에는 Adapter1.cpp, 2.cpp 같은 예제가 많습니다.

// C++에는 STL 만들때 몇가지 클래스에 어답터 패턴을 사용했습니다.


// 아래 코드가 STL 이 가진 stack의 실제 구현 모양입니다.
/*
template<typename T, typename C = deque<T>> 
class stack
{
	C c;
//	C* c; // 이렇게 포인터 또는 참조로 가지고 있어야 객체 어답터 입니다.
public:
	// 선형 컨테이너(list, vector, deque)의 멤버 함수 push_back() => push()로 변경해서
	// 스택처럼 보이게 만든것.
	inline void push(const T& a) { c.push_back(a); }
	inline void pop()            { c.pop_back(); }
	inline T&   top()            { return c.back(); }
};
*/
#include <stack> // 이 헤더의 내부에 위 코드가 있습니다.
				// STL 스택을 흔히 "stack adapter"라고 부릅니다.
				// STL의 컨테이너 어답터는 3개입니다. : stack, queue, priority_queue
int main()
{
	stack<int> s;
	s.push(10);

	stack<int, std::list<int> > s1;   // list를   스택처럼 사용할수있게 변경해 달라.
	stack<int, std::vector<int> > s2; // vector를 스택처럼 사용할수있게 변경해 달라.

	/*
	std::list<int> st; // list 객체를 먼저 만들고...
	st.push_back(10);  // 객체를 사용하다가.
	st.push_back(20);

	// list 객체 st 를 스택처럼 변경하고 싶다.
	stack<int> s3(&st); // 이렇게 할수 있어야 객체 어답터 입니다.
	*/
}
