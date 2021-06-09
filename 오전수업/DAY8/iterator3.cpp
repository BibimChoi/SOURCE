#include <iostream>

template<typename T>
struct Node
{
	T  data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};


// 1. 반복자의 함수 이름을 인터페이스로 약속하지 말자. - 가상함수를 사용하지 않기 위해
// 2. 함수 이름은 "진짜 포인터의 동작 방식으로 약속하자"
//    이동 : MoveNext() => operator++
//    접근 : GetObject() => operator*
template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;  // ++ 연산자 규칙, 자신을 참조로 반환
	}
	inline T& operator*() { return current->data; }
};

// slist_iterator<int> p(500);
// ++p; // 이동
// int n = *p; // p는 raw pointer 처럼 사용. 그리고, 인라인 치환가능


// 반복자를 꺼내는 함수는 begin()으로 약속합니다.(문서화)

template<typename T>
class slist
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	T front() { return head->data; }

	/*
	inline slist_iterator<T> begin()
	{
		return slist_iterator<T>(head); 
	}
	*/
	
	// 모든 컨테이너는 자신의 반복자 타입을 약속된 형태 "iterator" 로 외부에 노출해야한다.

	typedef slist_iterator<T> iterator;

	inline iterator begin()
	{
		return iterator(head);
	}

};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	
//	slist_iterator<int> p = s.begin();
//	vector_iterator<int> p = v.begin();  // 컨테이너에 따라 반복자 이름이 달라진다.


	slist<int>::iterator p = s.begin();


	std::cout << *p << std::endl;
	++p;

	std::cout << *p << std::endl;
	++p;

	std::cout << *p << std::endl;
}
