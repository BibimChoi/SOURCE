#include <iostream>
#include <list>
#include <vector>

// 요소를 2배로 하는 Visitor 
// 핵심 : Visitor는 결국 "한개의 요소에 대한 연산을 정의" 한 객체 입니다.
template<typename T> class TwiceVisitor
{
public:
	void Visit(T& e) { e = e * 2; }
};
// STL list는 방문자 패턴을 사용하지 않고 있는데, 사용하도록 확장해 봅시다.
template<typename T> class MyList : public std::list<T>
{
public:
	using std::list<T>::list;  // 기반 클래스인 list의 생성자를 상속해 달라.

	void Accept(TwiceVisitor<T>* visitor)
	{
		// 핵심 : list의 모든 요소를 방문자에게 전달 합니다.
		for (auto& e : *this)
			visitor->Visit(e);
	}
};
int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	
	TwiceVisitor<int> tv;
	s.Accept(&tv);       
}





