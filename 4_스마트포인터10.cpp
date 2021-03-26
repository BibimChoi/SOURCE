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
	}
	else
	{
		// 객체가 살아 있으므로 사용하고 싶다
//		wp->Go(); // error. weak_ptr은 -> 연산자가 재정의되어 있지 않다.

		// 객체에 접근 하려면 
		// 참조계수를 늘리고 사용해야 한다.
		// 참조계수를 늘리려면 shared_ptr을 다시 한개 만들어야 한다.
		std::shared_ptr<Car> sp2 = wp.lock();

		if (sp2)
			sp2->Go(); 
	}

	std::cout << "------" << std::endl;
}







