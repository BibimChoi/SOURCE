#include <iostream>

template<typename T>
struct Node
{
	T  data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};




// 반복자(열거자)를 만들어 봅시다. - C#버전(java도 유사합니다)

// 모든 반복자는 아래 인터페이스를 구현해야 한다.
// C# 1.0 버전
/*
struct IEnumerator
{
	virtual bool    MoveNext() = 0; // 이동
	virtual Object* GetObject() = 0;   // 요소 얻기
	virtual ~IEnumerator() {}
};
*/
// C# 2.0 - 인터페이스도 템플릿(Generic)으로!
template<typename T> struct IEnumerator
{
	virtual bool MoveNext() = 0;
	virtual T& GetObject() = 0;
	virtual ~IEnumerator() {}
};

// slist 의 반복자(열거자) 만들기
template<typename T> class slist_enumerator : public IEnumerator<T>
{
	Node<T>* current;
public:
	slist_enumerator(Node<T>* p = nullptr) : current(p) {}

	bool MoveNext() override 
	{
		current = current->next;
		return current; // 더이상 이동 불가능하면 false
	}
	T& GetObject() override
	{
		return current->data;
	}
};

//slist_enumerator<int> p(300번지);
//p.MoveNext();
//int n = p.GetObject();







// 모든 컨테이너에서는 반복자를 꺼내는 "GetEnumerator"가 있어야한다.

template<typename T> struct IEnumerable
{
	virtual IEnumerator<T>* GetEnumerator() = 0;
	virtual ~IEnumerable() {}
};

template<typename T>
class slist : public IEnumerable<T>
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
	T& front() { return head->data; }

	IEnumerator<T>* GetEnumerator() override
	{
		return new slist_enumerator<T>(head);
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
		
	// 반복자 꺼내서 사용하기
	IEnumerator<int>* p = s.GetEnumerator();
//	IEnumerator<int>* p = v.GetEnumerator(); // 핵심.. 컨테이너가 변경되어도 사용법이 동일해야한다.

	std::cout << p->GetObject() << std::endl;  // 40

	p->MoveNext();
	std::cout << p->GetObject() << std::endl;  // 30

	p->MoveNext();
	std::cout << p->GetObject() << std::endl;  // 20
}

// 위 방식을 STL 이 사용하지 않은 이유(단점)

// 1. MoveNext()등의 함수가 가상함수(인터페이스기반)로 되어 있다.
//    가상함수 호출의 오버헤드(컨테이너 안에 요소가 많을 경우)

// 2. 진짜 배열도 컨테이너이다.
//	  진짜 배열을 ++p 로 이동하고 *p 로 요소에 접근한다.
//    MoveNext() 와는 다른 방식이다.

// 3. GetEnumerator()가 반환한 반복자는 힙에 동적할당 되었다.
//    반드시 사용후 delete 해야 한다.
//    C#/java 는 "garbage collector" 가 있으므로 상관없다.





