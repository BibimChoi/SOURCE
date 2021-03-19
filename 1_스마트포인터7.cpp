#include <iostream>
#include <string>
#include <memory>

struct People
{
	std::string name;
	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	std::shared_ptr<People> bf;
};
int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	std::shared_ptr<People> sp2(new People("lee"));

	// 상호 참조 또는 순환참조(cycle reference)가 발생하면
	// 자원을 해지 되지 않습니다
	sp1->bf = sp2;
	sp2->bf = sp1;

}





