#include <iostream>

// 모델 2. 템플릿 기반

// 장점 :	타입 안정성이 좋고,
//			user type 뿐 아니라 primitive 타입도 저장가능
//			요소를 꺼낼때 캐스팅이 필요없다.

// 단점 : 템플릿 이므로 코드메모리가 증가할수있다.

template<typename T>
struct Node
{
	T  data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};

template<typename T>
class slist
{
	Node<T>* head = nullptr;
public:	
	void push_front(const T& a) { head = new Node<T>(a, head); }

	T front() { return head->data; }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
//	s.push_front(new Point); // error
	s.push_front(40); 

	int n = s.front();
}





