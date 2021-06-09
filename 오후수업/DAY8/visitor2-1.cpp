#include <iostream>
#include <list>
#include <vector>


// 방문자의 인터페이스
template<typename T> struct IVisitor
{
	virtual void Visit(T& e) = 0;
	virtual ~IVisitor() {}
};

template<typename T> class TwiceVisitor : public IVisitor<T>
{
public:
	void Visit(T& e) { e = e * 2; }
};

template<typename T> class ShowVisitor : public IVisitor<T>
{
public:
	void Visit(T& e) { std::cout << e << ", "; }
};

// 모든 요소를 0으로 하는 방문자
// 결국, 한개 요소에 대한 연산만 정의 한후
// 복합객체에 넣으면(Accept), 복합객체가 모든 요소를 visit로 보내 줍니다
template<typename T> class ZeroVisitor : public IVisitor<T>
{
public:
	void Visit(T& e) { e = 0; }
};


// 컨테이너는 방문자를 받아들여야 한다.
template<typename T> struct IAcceptor
{
	virtual void Accept(IVisitor<T>*) = 0;
	virtual ~IAcceptor() {}
};

template<typename T> class MyList : public std::list<T>, public IAcceptor<T>
{
public:
	using std::list<T>::list;  

	void Accept(IVisitor<T>* visitor)
	{
		for (auto& e : *this)
			visitor->Visit(e);
	}
};
int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.Accept(&tv);

	ShowVisitor<int> sv; // 모든 요소를 화면 출력하는 방문자
	s.Accept(&sv);

	// 방문자는 list 뿐아니라 모든 컨테이너를 방문해야 합니다.
//	MyVector<int> v = { 1,2,3,4 };
//	v.Accept(&tv);
}





