#include <iostream>
#include <string>
#include <memory>

struct People
{
	std::string name;
	People(std::string n) : name(n) {}
	~People() { std::cout << name << " �ı�" << std::endl; }

//	std::shared_ptr<People> bf; // best friend

	People* bf;  // raw pointer 
				 // ����ų�� ������ ������������� �ȵ�.
				// ���� : ����Ű�� ���� �ı� �Ǿ�������
				//    �����Ҽ��� ����.
				// "Dangling Pointer"�� ��Ÿ���� �ִ�.
				// �ּҴ� ������ �ش� �ּ��� ��ü��
				// �̹� �ı��� ����
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	
	{
		std::shared_ptr<People> sp2(new People("lee"));

		sp1->bf = sp2.get(); // bf�� raw pointer�̹Ƿ� get()���� �ڿ��ּ� �� �ֱ�
		sp2->bf = sp1.get();
	}

	if (sp1->bf != 0)
	{
		std::cout << sp1->bf->name << std::endl; 
	}

}







