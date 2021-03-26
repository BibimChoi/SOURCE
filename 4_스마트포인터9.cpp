#include <memory>
#include <string>
#include <iostream>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " �ı�" << std::endl; }

	//	std::shared_ptr<People> bf;
	// People* bf;		// raw pointer
	
	std::weak_ptr<People> bf; // ���� ��� ���� ����
							  // ��ü�� �ı� ���� ���簡��
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	{
		std::shared_ptr<People> sp2(new People("lee"));

		// weak_ptr�� shared_ptr�� �ٷ� ������ �ֽ��ϴ�.
		sp1->bf = sp2;
		sp2->bf = sp1;
	} // "lee" �� �ı� �ȴ�.

	if (sp1->bf.expired() )
	{
		std::cout << "����Ű�� ��ü �ı�" << std::endl;
	}
}



