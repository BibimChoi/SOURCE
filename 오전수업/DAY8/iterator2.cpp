#include <iostream>

template<typename T>
struct Node
{
	T  data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};

//-----------------------------------------------
// 반복자(iterator), enumerator(열거자) 라고도 합니다.

// 모든 반복자는 사용법이 동일해야 한다. - 공통의 인터페이스 설계

/*
// C# 1.0 때는 아래와 같은 인터페이스 사용
// 즉, 컨테이너가 Object 기반 컨테이너 였습니다.
struct IEnumerator
{
	virtual bool MoveNext() = 0;
	virtual Object* GetObject() = 0; // C# 1.0
	virtual ~IEnumerator() {}
};
*/
// C# 2.0 부터 Generic(template) 문법이 도입되고 반복자 인터페이스가 아래처럼 변경됩니다.
template<typename T>
struct IEnumerator
{
	virtual bool MoveNext() = 0;
	virtual T& GetObject() = 0; // C# 2.0
	virtual ~IEnumerator() {}
};

// slist의 반복자를 만들어 봅시다.
// 반복자 : 컨테이너의 요소를 가리키다가 약속된 방식으로 열거하는 객체
template<typename T> class slist_enumerator : public IEnumerator<T>
{
	Node<T>* current;
public:
	slist_enumerator(Node<T>* p = nullptr) : current(p) {}

	bool MoveNext() override
	{
		current = current->next;
		return current;  // 더이상 이동 불가능하면 false 반환
	}
	T& GetObject() override { return current->data; }
};

//slist_enumerator<int> p(500번지);
//p.MoveNext(); // 다음으로 이동
//int n = p.GetObect()

// 모든 컨테이너는 반복자를 꺼낼때 사용할 함수가 있어야 합니다.
// 인터페이스로 약속합니다(컨테이너가 지켜야 하는 규칙)
template<typename T> struct IEnumerable
{
	virtual IEnumerator<T>* GetEnumerator() = 0;
	virtual ~IEnumerable() {}
};

template<typename T>
class slist :  public IEnumerable<T>
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	T front() { return head->data; }

	IEnumerator<T>* GetEnumerator() override
	{
		return new slist_enumerator<T>(head); // list 용 반복자를 만들어서 반환
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	// 열거하려면 반복자를 꺼냅니다.
	IEnumerator<int>* p = s.GetEnumerator();

	std::cout << p->GetObject() << std::endl; // 40

	p->MoveNext();
	std::cout << p->GetObject() << std::endl; // 30

	p->MoveNext();
	std::cout << p->GetObject() << std::endl;  // 20

}


// 이 방식의 단점
// 1. MoveNext()등이 가상함수 이다. ==> 컨테이너에 요소가 많은 경우 오버헤드가 있다.

// 2. Raw Array는 반복자라는 개념이 없다. 포인터로 열거한다.
//	  그런데, 포인터는 MoveNext가 아니라 ++로 이동한다. => 열거 방식이 다르다.

// 3. GetEnumerator()로 얻게 되는 반복자는 "new" 로 만들어졌다.. 
//    반드시 delete 해야 한다.(또는 스마트 포인터 사용)\
//	  C#/Java 는 Garbage collector 가 있으므로 상관없는데..
//	  C++에서는 좋지 않다.


