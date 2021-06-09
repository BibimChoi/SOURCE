#include <iostream>
#include <list>
#include <vector>

// 모든 방문자는 아래 인터페이스를 구현해야 한다.
template<typename T> struct IVisitor
{
	virtual void Visit(T& e) = 0;   // 인자가 참조라는 것이 해심입니다.
	virtual ~IVisitor() {}
};
// 모든 컨테이너는 방문자의 방문을 허락해야한다.
template<typename T> struct IAcceptor
{
	virtual void Accept(IVisitor<T>* v) = 0;
	virtual ~IAcceptor() {}
};

// STL 리스트는 방문자 패턴을 사용하지 않으므로
// 방문자패턴을 사용하도록 기능 추가
template<typename T> class MyList : public std::list<T>, public IAcceptor<T>
{
public:
	using std::list<T>::list; // 생성자 상속

	void Accept(IVisitor<T>* v) override
	{
		// 방문자 패턴의 핵심입니다.. 잘 생각해 보세요.. 어렵지 않습니다
		// 자신의 모든 요소를 방문자의 Visit 함수에 전달합니다.
		for (auto& e : *this)
			v->Visit(e);
	}
};
//-----------------------------------
// 이제 다양한 종류의 방문자를 제공하면 됩니다.
// 결국 방문자는 "한개의 요소에 대한 연산"을 하는 객체 입니다.

template<typename T> struct TwiceVisitor : public IVisitor<T>
{
	void Visit(T& e) override { e = e * 2; }
};

template<typename T> struct ShowVisitor : public IVisitor<T>
{
	void Visit(T& e) override { std::cout << e << ", ";  }
};

template<typename T> struct ZeroVisitor : public IVisitor<T>
{
	void Visit(T& e) override { e = 0; }
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv; 
	s.Accept(&tv);        

	ShowVisitor<int> sv; // 모든 요소를 출력하는 방문자
	s.Accept(&sv);

	ZeroVisitor<int> zv; // 모든 요소를 0으로
	s.Accept(&zv);

}









