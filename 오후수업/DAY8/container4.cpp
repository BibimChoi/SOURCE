#include <iostream>

// 모델 3. 메모리가 부족한 임베디드 환경에서 많이 사용했던 기술





// 1. void* 기술로 컨테이너를 구현합니다.
struct Node
{
	void*  data;
	Node* next;
	Node(void* d, Node* n) : data(d), next(n) {}
};
class slistImpl
{
	Node* head = nullptr;
public:
	void push_front(void* a) { head = new Node(a, head); }
	void* front() { return head->data; }
};

// 실제 컨테이너의 모든 구현은 void*로 구현하고..
// 자동으로 캐스팅을 하기 위해 템플릿을 제공합니다.
template<typename T> class slist : public slistImpl
{
public:
	// 실제 구현은 기반 클래스 함수를 호출한다. 
	// 아래 함수의 목표는 캐스팅 입니다.
	void push_front(const T& a) { slistImpl::push_front((void*)a); }
	T front()                   { return (T)slistImpl::front(); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40); 

	int n = s.front(); 
}




