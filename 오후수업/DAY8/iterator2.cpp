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

	std::cout << p->GetObject() << std::endl;  // 40

	p->MoveNext();
	std::cout << p->GetObject() << std::endl;  // 30

	p->MoveNext();
	std::cout << p->GetObject() << std::endl;  // 20

}




