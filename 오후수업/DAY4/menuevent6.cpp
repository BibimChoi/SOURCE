#include <iostream>
#include <functional>
using namespace std::placeholders;

class Camera
{
public:
	void take(int a, int b) { std::cout << "Camera take" << std::endl; }
};

void foo(int a) { std::cout << "foo : " << a << std::endl; }
void goo(int a, int b) { std::cout << "goo : " << a << b << std::endl; }
void hoo(int a, int b, int c) { std::cout << "hoo : " << a << b << c << std::endl; }

int main()
{
	// C언어의 함수 포인터는 유연성이 없습니다. 
	void(*pf)(int) = &foo;

	pf(10); // ok.. foo(10);

//	pf = &goo; // error

	// C++11 의 function 은 함수포인터를 일반화한 클래스입니다. 아주 유연성이 많습니다.
	// 사용법 : std::function<함수모양>

	std::function< void(int) > f;

	f = &foo;
	
	f(10); // ok.. foo(10)


	// bind를 사용해서 인자를 고정하면 f에 인자가 여러개인 함수도 담을수 있습니다
	f = std::bind(&goo, 5, _1 ); // 2항함수 => 1항함수로 변경해서 f넣기

	f(10); // goo(5, 10)


	f = std::bind(&hoo, 3, _1, 6);
	f(10); // hoo(3, 10, 6)

	// 멤버 함수도 됩니다. 인자가 2개인 멤버함수는 인자가 3개로 생각하세요(객체까지)
	Camera cam;
	f = std::bind(&Camera::take, &cam, 3, _1);
	f(10); // cam.take(3, 10)

	// bind의 반환값은 진짜 함수는 아닌. 함수역활의 어떤 객체 입니다.
	// 따라서 진짜 함수포인터와는 호환 안됩니다.
	void(*pf)(int) = std::bind(&goo, 5, _1); //error

	// bind와 호환 되게 하려면 function을 사용합니다.

}









