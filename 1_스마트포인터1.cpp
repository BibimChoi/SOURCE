

// github.com/codenuri/SOURCE 에서 DAY10.zip 받으세요


// SMART_POINTER_AND_THREAD.pdf 도 받아 두세요


// "삼성_MODERNCPP시험문제.zip" 도 받아두세요 - 암호는 4교시에 알려 드리겠습니다.


// VS 사용하시는 분은 "windows sdk 버전" 설정해 주세요







#include <iostream>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
	~Car()    { std::cout << "~Car" << std::endl; }
};
// 개념 : 객체가 다른 타입의 포인터 역활을 하는 것.
// 원리 : -> 와 * 연산자를 재정의해서 포인터 처럼 보이게 하는것
// 장점 : raw pointer 가 아닌 "객체" 이다.
//		  생성/복사/대입/소멸의 모든 과정에 추가작업을 할수 있다
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = nullptr) : obj(p) {}

	~Ptr() { delete obj; }

	Car* operator->() { return obj; }
	Car& operator*()  { return *obj; } // 핵심. 참조리턴이
										// 필요
};

int main()
{
	Ptr p = new Car; // Ptr p(new Car )

	p->Go(); // p.operator->() Go() 모양이지만
			 // (p.operator->())->Go() 처럼 해석됩니다.

	(*p).Go();// p.operator*()
}




