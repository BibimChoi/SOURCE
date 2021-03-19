#include <iostream>
#include <string>
#include <memory>

struct People
{
	std::string name;
	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

//	std::shared_ptr<People> bf; // best friend

	People* bf;  // raw pointer 
				 // 가리킬수 있지만 참조계수증가는 안됨.
				// 단점 : 가리키던 곳이 파괴 되었는지를
				//    조사할수가 없다.
				// "Dangling Pointer"가 나타날수 있다.
				// 주소는 있지는 해당 주소의 객체는
				// 이미 파괴된 상태
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	
	{
		std::shared_ptr<People> sp2(new People("lee"));

		sp1->bf = sp2.get(); // bf가 raw pointer이므로 get()으로 자원주소 얻어서 넣기
		sp2->bf = sp1.get();
	}

	if (sp1->bf != 0)
	{
		std::cout << sp1->bf->name << std::endl; 
	}

}







