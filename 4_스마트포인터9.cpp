#include <memory>
#include <string>
#include <iostream>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	//	std::shared_ptr<People> bf;
	// People* bf;		// raw pointer
	
	std::weak_ptr<People> bf; // 참조 계수 증가 안함
							  // 객체의 파괴 여부 조사가능
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	{
		std::shared_ptr<People> sp2(new People("lee"));

		// weak_ptr에 shared_ptr를 바로 담을수 있습니다.
		sp1->bf = sp2;
		sp2->bf = sp1;
	} // "lee" 가 파괴 된다.

	if (sp1->bf.expired() )
	{
		std::cout << "가리키던 객체 파괴" << std::endl;
	}
}



