#include <iostream>
#include <functional>
using namespace std::placeholders;

class Camera
{
public:
	void take(int a, int b) { std::cout << "Camera take" << std::endl; }
};

void foo(int a)        { std::cout << "foo : " << a << std::endl; }
void goo(int a, int b) { std::cout << "goo : " << a << b << std::endl; }
void hoo(int a, int b, int c) { std::cout << "hoo : " << a << b << c << std::endl; }

int main()
{
	// C의 함수 포인터는 유연성이 부족해서.. 사용하기 불편 합니다.
	void(*pf)(int) = &foo;
	pf(10); // ok.. foo(10);
//	pf = &goo; // error. goo는 인자가 2개 입니다.

	// C++ 의 std::function 인 편리합니다.
	// std::function<주소를 저장할 함수모양> f;
	std::function<void(int)> f;

	f = &foo; // ok
	f(10);	  // foo(10) 과 동일

	
	f = std::bind(&goo, 3, _1); // function 은 bind와 같이 사용하면 유연성이 좋아집니다
	f(10); // goo(3, 10)

	f = std::bind(&hoo, 2, _1, 9);
	f(10); // hoo(2, 10, 9) 처럼 호출됩니다.

	// 결국 f에는 인자가 한개 이상인 모든 함수가 저장될수 있습니다.(bind 덕분에...)
	// 멤버 함수도 됩니다... 객체를 1번째 인자로 생각하세요

	Camera cam;

	// take는 인자가 2개이지만, 멤버함수 이므로 인자를 3개로 생각하고 bind하세요
	f = std::bind(&Camera::take, &cam, _1, 7 );

	f(5);// cam.take(5, 7) 처럼 호출됩니다.


}







