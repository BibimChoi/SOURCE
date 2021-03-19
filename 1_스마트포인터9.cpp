#include <iostream>
#include <string>
#include <memory>

struct People
{
	std::string name;
	People(std::string n) : name(n) {}
	~People() { std::cout << name << " �ı�" << std::endl; }

	//	std::shared_ptr<People> bf; // best friend

	//People* bf;  

	std::weak_ptr<People> bf; // ������� ��������
							// ����Ű�� ���� �ı� �Ǿ�����
							// ���� ����
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));

	{
		std::shared_ptr<People> sp2(new People("lee"));

		sp1->bf = sp2; 
		sp2->bf = sp1;
	}  // sp2 �� "lee" �ı�

	if (sp1->bf.expired() ) // ����Ű�� ���� �ı� �Ǿ����� ����
	{
		std::cout << "��ü �ı���" << std::endl;
	}

}







