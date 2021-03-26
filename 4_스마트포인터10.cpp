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

	std::cout << "------" << std::endl;
}

