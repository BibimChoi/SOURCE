#include <iostream>

template<typename T>
struct Node
{
	T  data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};




// STL 버전의 반복자

// 1. 함수의 이름을 진짜 포인터의 연산과 동일하게

template<typename T> class slist_iterator 
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this; // ++연산자 규칙(자신의 참조 반환)
	}

	inline T& operator*()
	{
		return current->data;
	}
};


template<typename T>
class slist 
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
	T& front() { return head->data; }

	/*
	slist_iterator<T> begin()
	{
		return slist_iterator<T>(head); // new를 사용하지 않고. 일반 스택객체로 반환
	}
	*/

	// 모든 컨테이너 설계자는 자신의 반복자 이름을 "iterator" 라는 약속된
	// 형태로 외부에 노출하기로 약속하자.
	typedef slist_iterator<T> iterator;

	iterator begin() {	return iterator(head);	}
};
int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	slist<int>::iterator p = s.begin();

//	slist_iterator<int> p = s.begin();
//	vector_iterator<int> p = v.begin();

	std::cout << *p << std::endl;

	++p;
	std::cout << *p << std::endl;

	++p;
	std::cout << *p << std::endl;

}



