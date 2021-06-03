// 3_메뉴이벤트7.cpp   => 메뉴이벤트1 복사해오세요.
#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <memory> // 스마트 포인터!
#include <functional>
using namespace std::placeholders; // _1, _2 



class BaseMenu
{
	std::string title;
public:
	BaseMenu(std::string s) : title(s) {}

	std::string getTitle() const { return title; }

	virtual void command() = 0;
};



class PopupMenu : public BaseMenu
{
	std::vector< std::shared_ptr<BaseMenu> > v;
public:
	PopupMenu(std::string s) : BaseMenu(s) {}

	void addMenu(std::shared_ptr<BaseMenu> p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");
			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->getTitle() << std::endl;
			}
			std::cout << sz + 1 << ". 상위 메뉴로 이동" << std::endl;

			int cmd;
			std::cout << "메뉴를 선택해 주세요 >> ";
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command();

		}
	}
};
//-----------------------------------------------------
// 방법 4. std::function 을 사용한 이벤트 처리
class MenuItem : public BaseMenu
{
	int id;
	using HANDLER = std::function<void()>;

	HANDLER handler = nullptr;
public:
	MenuItem(std::string s, int n, HANDLER h = nullptr) 
			: BaseMenu(s), id(n), handler(h) {}

	void setHandler(HANDLER h) { handler = h; }

	void command() override
	{
		if (handler) handler();
	}
};
//----------------------------------------
void foo()       { std::cout << "foo" << std::endl; }
void goo(int id) { std::cout << "goo : " << id << std::endl; }

int main()
{
	std::shared_ptr<MenuItem> p1 = std::make_shared<MenuItem>("RED", 11, &foo);
	std::shared_ptr<MenuItem> p2 = std::make_shared<MenuItem>("BLUE", 12, std::bind(&goo, 12) );
	std::shared_ptr<MenuItem> p3 = std::make_shared<MenuItem>("WHITE", 13, std::bind(&goo, 13));
	
	std::shared_ptr<MenuItem> p4 = std::make_shared<MenuItem>("BLACK", 14); // 아직핸들러등록안함
	
	p4->setHandler([]() { std::cout << "lambda handler" << std::endl; });

	// 그외.. 멤버 함수등 모든 종류의 함수가 메뉴 핸들러로 등록될수 있습니다.

	p1->command();
	p2->command();
	p3->command();
	p4->command();
}







