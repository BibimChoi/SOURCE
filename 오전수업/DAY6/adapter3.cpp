#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;

// STL 과 adapter..
// STL의 스택은 아래처럼 만들어져 있습니다.
/*
template<typename T, typename C = deque<T>> 
class stack
{
	C c;
public:
	// push_back()이라는 함수를 push()로 바꾸어서, 스택 처럼 보이게 한다.
	void push(const T& a) { c.push_back(a); }
	void pop()            { c.pop_back(); }
};
*/
#include <stack> // 이 안에 있는 STL stack 이 위처럼 되어 있습니다.
				 // "stack adapter"라고 부릅니다.
				 // 선형 컨테이너를 stack 처럼 보이도록 인터페이스(함수이름)만 변경한 도구
				 // 3개의 컨테이너 어답터가 있습니다. : stack, queue, priority_queue
int main()
{
	stack<int> s;
	s.push(10);

	stack<int, std::list<int>>   s1; // list 를 스택처럼 보이게 변경해 달라
	stack<int, std::vector<int>> s2; // vector 를 스택처럼 보이게 변경해 달라

	// STL 의 "컨테이너 어답터"는 클래스 어답터 입니다.

	// 객체어답터가 되려면 아래 처럼 사용할수 있어야 합니다.
	std::list<int> st; // list 객체를 먼저 만들고
	st.push_back(10);
	st.push_back(20); // list 객체를 사용하다가..

	// 이제 부터 st라는 객체를 스택처럼 사용하고 싶다.!!
	stack<int> s3(&st); // 이렇게 사용할수 있다면 객체 어답터
	int n = s3.top(); // st.back()
}



