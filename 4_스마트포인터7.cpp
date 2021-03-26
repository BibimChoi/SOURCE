#include <memory>
#include <string>
#include <iostream>

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

	// 아래 코드 때문에 "상호 참조","순환 참조" 가 발생합니다.
	// 자원이 삭제될수 없습니다. 자원 누수
	sp1->bf = sp2;
	sp2->bf = sp1;
}



