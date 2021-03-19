#include <iostream>
#include <string>
#include <memory>

struct People
{
	std::string name;
	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	//std::shared_ptr<People> bf;
	//People* bf;
				
	std::weak_ptr<People> bf;  // 1. 참조계수 증가 안함
							   // 2. 객체 파괴 여부 조사 가능
};
int main()
{
	std::shared_ptr<People> sp1(new People("kim"));

	{
		std::shared_ptr<People> sp2(new People("lee"));

		sp1->bf = sp2;
		sp2->bf = sp1;
	} 

	if (sp1->bf.expired() ) // 가리키던 곳이 파괴 되었는지 조사
	{
		std::cout << "객체가 파괴됨" << std::endl;
	}
}







