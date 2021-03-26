#include <memory>
#include <string>
#include <iostream>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " �ı�" << std::endl; }

//	std::shared_ptr<People> bf;

	People* bf;		// raw pointer
					// ��������� �������� �ʴ´�.
					// ������ "��ü �ı��� �����Ҽ� ����."
					// "Dangling Pointer" �� ����!!!
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	{
		std::shared_ptr<People> sp2(new People("lee"));

		sp1->bf = sp2.get();
		sp2->bf = sp1.get();
	} // "lee" �� �ı� �ȴ�.

	if (sp1->bf != nullptr )
	{
		std::cout << sp1->bf->name << std::endl;
	}
}



