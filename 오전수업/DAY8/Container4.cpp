#include <iostream>

// 모델 3. 메모리가 부족한 임베디드 환경에서 많이 사용했던 모델..

// C언어에서 널리 사용했던 void* 기반 "일반화된 list" 만드는 기술을 사용해 봅시다.
struct Node
{
	void* data;
	Node* next;
	Node(void* d, Node* n) : data(d), next(n) {}
};

// 실제 list의 구현을 담은 클래스 ( void* 기술 사용)
class slistImpl
{
	Node* head = nullptr;
public:
	void push_front(void* a) { head = new Node(a, head); }
	void* front() { return head->data; }
};

// slistImpl 을 직접 사용하면 "항상 캐스팅 코드" 가 나오기 때문에 불편합니다.
// 이제, 캐스팅만 책임지는 클래스 템플릿을 제공합니다.

// "Thin Template 또는 Template hoisting" 이라고 불리는 기술입니다.
// 메모리가 부족한 환경에서 "캐스팅만 책임지는 템플릿"을 만드는 기술
// github.com/aosp-mirror
// platform system core
// libutils/include/utils/vector.h   vectorImpl.h
// C++ Idioms 사이트에서 "Thin Template" 참고
template<typename T> class slist : private slistImpl
template<typename T> class slist : public slistImpl
{
public:
	void push_front(const T& a) { slistImpl::push_front((void*)a); }
	T front() { return (T)slistImpl::front(); }
};

// 이제 사용자는 slist를 사용하게 합니다.
int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40); 

	int n = s.front();
}




