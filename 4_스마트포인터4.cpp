#include <iostream>

// C++11�� ����Ʈ�����͸� ����Ϸ��� �ʿ��� ���
#include <memory>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
};

int main()
{
	// �ٽ� 1. () �ʱ�ȭ�� �����ϴ�.
	std::shared_ptr<int> p1(new int);  // ok
//	std::shared_ptr<int> p2 = new int; // error. �����ڰ� explict ������



	// �ٽ� 2. ����Ʈ �������� ũ��
	std::cout << sizeof(p1)   << std::endl; // 8
	std::cout << sizeof(int*) << std::endl; // 4 ( 32bit)



	// �ٽ� 3. -> �� . ������
	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;

	// ����Ʈ �����ʹ� ��� "��ü" �Դϴ�.

	// -> : ���ü(Car)�� ����Լ� ����
	sp1->Go();

	// . : shared_ptr ��ü�� ��� �Լ� ���
	int n = sp1.use_count(); // 2
	Car* p = sp1.get();    // �ڿ��� raw pointer ���
	sp1.reset();  // sp1 = nullptr

}



