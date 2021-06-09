#include <iostream>

// 모델 1. Object 기반 컨테이너
// 단점 1. 타입 안정성이 좋지 않다.
// 단점 2. 사용자 정의 타입이 아닌 primitive type(int등)은 보관할수 없다.
//         그래서 java 는 int 와 Integer 가 있다.
//			C#은 int 도 Object 로 부터 파생된다.
// 단점 3. 요소를 꺼낼때 항상 캐스팅 필요

// 장점 : 템플릿이 아니므로 코드 메모리 사용량이 증가하지 않음.

// 라이브러리의 최상위 클래스로 사용할 Object 클래스를 만들고
class Object {};


// 라이브러리 내부의 모든 클래스는 Object로 부터 파생되어야 한다.
class Point  : public Object {};
class Dialog : public Object {};
class LedService  : public Object {};


// 이제 컨테이너는 Object*를 보관하도록 설계한다.

struct Node
{
	Object*  data;
	Node* next;
	Node(Object* d, Node* n) : data(d), next(n) {}
};

class slist
{
	Node* head = nullptr;
public:
	void push_front(Object* a) { head = new Node(a, head); }

	Object* front() { return head->data; }
};

int main()
{
	slist s;
	s.push_front(new Point);
	s.push_front(new Point);
	s.push_front(new Dialog); // 실수 일수 있는데..에러가 나지 않는다. 
//	s.push_front(40);         // error. int 는 Object로 부터 파생되지 않는다.
	s.push_front(new Point);

//	Point* p = s.front(); // error. 캐스팅 필요
	Point* p = static_cast<Point*>(s.front()); // error. 캐스팅 필요
}




