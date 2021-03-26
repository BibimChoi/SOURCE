#include <memory>
#include <string>
#include <iostream>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

//	std::shared_ptr<People> bf;

	People* bf;		// raw pointer
					// 참조계수가 증가하지 않는다.
					// 문제는 "객체 파괴를 조사할수 없다."
					// "Dangling Pointer" 의 등장!!!
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	{
		std::shared_ptr<People> sp2(new People("lee"));

		sp1->bf = sp2.get();
		sp2->bf = sp1.get();
	} // "lee" 가 파괴 된다.

	if (sp1->bf != nullptr )
	{
		std::cout << sp1->bf->name << std::endl;
	}
}



