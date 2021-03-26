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
		// ��ü�� ��� �����Ƿ� ����ϰ� �ʹ�
//		wp->Go(); // error. weak_ptr�� -> �����ڰ� �����ǵǾ� ���� �ʴ�.

		// ��ü�� ���� �Ϸ��� 
		// ��������� �ø��� ����ؾ� �Ѵ�.
		// ��������� �ø����� shared_ptr�� �ٽ� �Ѱ� ������ �Ѵ�.
		std::shared_ptr<Car> sp2 = wp.lock();

		if (sp2)
			sp2->Go(); 
	}

	std::cout << "------" << std::endl;
}







