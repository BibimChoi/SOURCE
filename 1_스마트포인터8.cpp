#include <iostream>
#include <string>
#include <memory>

struct People
{
	std::string name;
	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	//std::shared_ptr<People> bf;
	People* bf; // raw pointer : 참조계수가 증가 안함
				// 단점 : 가리키던 곳의 객체가 파괴 되었는지
				//       조사할수 없다
				// dangling pointer 의 등장!!!

};
int main()
{
	std::shared_ptr<People> sp1(new People("kim"));

	{
		std::shared_ptr<People> sp2(new People("lee"));

		sp1->bf = sp2.get();
		sp2->bf = sp1.get();
	} // sp2 가 가리키던 객체 파괴.

	if (sp1->bf != nullptr)  // 안전하게 주소 조사먼저하고
	{
		std::cout << sp1->bf->name << std::endl;  // 사용
	}
}







