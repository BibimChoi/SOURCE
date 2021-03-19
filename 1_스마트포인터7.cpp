#include <iostream>
#include <string>
#include <memory>

struct People
{
	std::string name;
	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	std::shared_ptr<People> bf; // best friend
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	std::shared_ptr<People> sp2(new People("lee"));

	// shared_ptr 사용시 "상호참조", "순환참조(cycle reference)"
	// 발생시 자원 누수가 있습니다.
	sp1->bf = sp2;
	sp2->bf = sp1;
}


