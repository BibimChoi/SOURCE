#include <iostream>
#include <memory>

class Car
{
public:
	void Go() {}
	~Car() {std::cout << "~Car" << std::endl;	}
};
int main()
{
	std::weak_ptr<Car>   wp;
	{
		std::shared_ptr<Car> p(new Car);
	
		wp = p; 
		
		std::cout << p.use_count() << std::endl; // 
	}

	if (wp.expired())
	{
		std::cout << "객체 파괴" << std::endl;
	}
	else
	{
		// 아직 객체가 살아 있으므로 객체에 접근해 봅시다.
		wp->Go(); // Error. weak_ptr에는 -> 연산자가 없다

		// 객체가 살아 있어도 wp로는 절대 접근이 안됩니다
		// 접근 하려면 "참조계수를 증가" 하고 접근해야 합니다.
		// 참조계수를 증가하는 법은 shared_ptr을 만들어야 한다.
		std::shared_ptr<Car> sp2 = wp.lock();

		if (sp2) // 다시 확인
			sp2->Go();

	}

	std::cout << "------" << std::endl;
}

