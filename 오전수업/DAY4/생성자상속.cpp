// 생성자상속.cpp
class Base
{
	int x, y;
public:
	Base(int a, int b) : x(a), y(b) {}
};

// 파생 클래스를 만드는데, 상태는 추가하지 않고, 동작만 추가하려고 합니다.
class Derived : public Base
{
public:
	// 예전 스타일 - 인자를 받아서 기반 클래스에 전달했습니다.
	//Derived(int a, int b) : Base(a, b) {}

	// 위처럼 전달받은 인자를 바로 기반 클래스의 생성자로 보낼때는
	// C++11부터는 아래처럼 하면됩니다.
	using Base::Base;  // 생성자를 상속해 달라! - 위 코드와 동일한 효과!!

	void foo() {}
};
int main()
{
	Base b(1, 2);	// ok
	Derived d(1, 3);// ok..
}
