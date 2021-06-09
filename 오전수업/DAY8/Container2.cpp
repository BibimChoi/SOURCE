#include <iostream>

// 모델 1. object 기반 컨테이너..
// 단점 : 타입 안정성이 좋지 않고, 
//        사용자 정의 타입이 아닌 primitive type(int, double) 을 저장할수 없다.
//        요소를 꺼낼때 캐스팅이 필요 한다.
// 장점 : 템플릿이 아니므로 "Code Bloat(코드메모리가 증가하는 현상)" 이 없다.

// 라이브러리 설계시 단일 최상위 클래스를 하나 설계
class object {};

// 라이브러리 내의 모든 클래스는 object 로 부터 파생되어야 한다.. 는 규칙을 정한다.
class Dialog : public object {};
class Point  : public object {};
class LedService : public object {};

// 이제 모든 컨테이너는 object* 를 보관하게 하면 
// 라이브러리내의 모든 객체를 보관할수 있다.
struct Node
{
	object*   data;
	Node* next;
	Node(object* d, Node* n) : data(d), next(n) {}
};
class slist
{
	Node* head = nullptr;
public:
	void push_front(object* a) { head = new Node(a, head); }

	object* front() { return head->data; }
};

int main()
{
	slist s;
	s.push_front(new Point);
	s.push_front(new Point);
//	s.push_front(new Dialog); // s가 아닌 다른 리스트(s2)를 사용하는 것을
						// 실수로 s로 적었을수 있다.
						// 그런데. 에러가 발생하지 않는다
						// "타입 안전성이 좋지 않다." 라고 표현
//	s.push_front(40);	// error. int 는 object 로 부터 파생되지 않는다.

	s.push_front(new Point);

//	Point* p = s.front(); // error. 캐스팅 필요
	Point* p = static_cast<Point*>(s.front()); //ok.. 
}




