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
	std::shared_ptr<Car> sp;
	std::weak_ptr<Car>   wp;
	
//	{
		std::shared_ptr<Car> p(new Car);
	
		//sp = p;  // 참조계수 2.
		wp = p;		// 참조계수 증가 안함. 계속 1.
		std::cout << p.use_count() << std::endl; // 1
//	} // p 파괴.. 즉 객체도 파괴

	if (wp.expired())
	{
		std::cout << "자원 파괴" << std::endl;
	}
	else
	{
		// wp로 객체 사용
		wp->Go(); // error.. 그런데.. 안된다!!!

		// wp로 객체에 접근하려면 "다시 shared_ptr을 만들어서 참조계수를 증가한후"
		// 접근해야 한다.
		std::shared_ptr<Car> sp2 = wp.lock();

		if (sp2) // 안전한지 확인하고
			sp2->Go(); // 사용해야 한다.
	}

	std::cout << "------" << std::endl;
}

