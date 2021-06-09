#include <iostream>

// 모델 2. 템플릿 기반 컨테이너
// 장점 : 타입안전성이 좋고, primitive type 도 저장 가능. 꺼낼때 캐스팅 필요 없다.

// 단점 : 템플릿 기반 이므로 코드 메모리가 증가 할수도 있다.


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

	T& front() { return head->data; }
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




