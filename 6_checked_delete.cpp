#include <iostream>

class Test; // 클래스 전방 전언
			// 불완전타입(incomplete type)
			// 불완전 타입은 delete 시 소멸자가 호출되지 않는다.

class Test
{
public:
	Test()  { std::cout << "Test()" << std::endl; }
	~Test() { std::cout << "~Test()" << std::endl; }
};

void foo(Test* p)
{
	static_assert(sizeof(Test) > 0, "error, delete incomplete type");
	delete p;
}

int main()
{
	Test* p = new Test;
	foo(p);
}
