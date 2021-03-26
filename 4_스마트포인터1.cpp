#include <iostream>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
	~Car()    { std::cout << "~Car" << std::endl; }
};

// Ptr 이 핵심입니다.
// 개념 : 임의의 객체가 다른 타입의 포인터 역활을 하는 것
// 원리 : -> 연산자와 *연산자를 재정의 해서 포인터 처럼 보이게 한다.
// 장점 : Raw Pointer 가 아닌 객체이다.
//		생성/복사/대입/파괴의 모든 과정에서 추가의 작업을 할수 있다
//		대표적인 활용이 소멸자에서의 자원 자동삭제
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}
	
	~Ptr() { delete obj; }

	Car* operator->() { return obj; }
	Car& operator*()  { return *obj; }
};
int main()
{
	Ptr p = new Car;  // Ptr p(new Car)

	p->Go(); //  (p.operator->()) Go() 의 모양이지만
			 //  (p.operator->())->Go() 로 해석됩니다.
	(*p).Go();
}


