#include <iostream>

struct Base
{
	int value = 10; 

	Base()  { std::cout << "Base()" << std::endl; }
	Base(const Base& b) : value(200)  { std::cout << "Base()" << std::endl; }
	~Base() { std::cout << "~Base()" << std::endl; }
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;
	std::cout << d.value << std::endl;  // 20
	std::cout << d.Base::value << std::endl;  // 10

	std::cout << "-------------" << std::endl;
	std::cout << static_cast<Base>(d).value << std::endl;  // 10
	std::cout << "-------------" << std::endl;
	std::cout << static_cast<Base&>(d).value << std::endl;  // 10

//	static_cast<Base>(d).value = 20;  // error
//	static_cast<Base&>(d).value = 20; // ok

}

