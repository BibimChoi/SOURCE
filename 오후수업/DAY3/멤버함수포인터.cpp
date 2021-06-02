// 멤버함수포인터
#include <iostream>
#include <functional>

class Car
{
public:
	void Go(int speed) { std::cout << "Car Go" << std::endl; }
	void Stop()        { std::cout << "Car Stop" << std::endl; }
};
int main()
{
	Car c;

	// 1. 멤버 함수포인터를 직접사용하면
	void(Car::*f1)(int) = &Car::Go;
	(c.*f1)(80); // 이렇게 사용해야 합니다. c.Go(80)의 의미

	// 2. std::mem_fn (C++11이후나오는)을 사용하면 좀더 편리합니다.
	auto f2 = std::mem_fn(&Car::Go);
	// 반환된 f2는 멤버 함수 포인터를 쉽게 사용할수 있는 객체입니다.
	// ()로 호출하면서 객체를 1번째 인자로 보내면 됩니다.

	f2(c, 80); // c.Go(80) 의 의미

	std::cout << typeid(f2).name() << std::endl; // mem_fn의 반환 타입 구하기
											// 컴파일러마다 다릅니다.
}






