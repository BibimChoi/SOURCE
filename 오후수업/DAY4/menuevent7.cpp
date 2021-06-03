// 3_메뉴이벤트7.cpp 추가하세요. 메뉴이벤트 복사해오세요

#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <memory> // 스마트 포인터!

#include <functional> // std::bind, std::function
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

	void addMenu(std::shared_ptr<BaseMenu>  p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size(); // 하위 메뉴 갯수

			for (int i = 0; i < sz; i++)
				std::cout << i + 1 << ". " << v[i]->getTitle() << std::endl;

			std::cout << sz + 1 << ". 상위 메뉴로" << std::endl;

			std::cout << "메뉴를 선택하세요 >> ";
			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command();
		}
	}
};

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
		// 메뉴 선택시 등록된 함수 호출
		if (handler) handler();
	}
};
// ---------------
void foo()       { std::cout << "foo" << std::endl; }
void goo(int id) { std::cout << "goo : " << id << std::endl; }

class Camera
{
public:
	void take(int a, int b) { std::cout << "take" << std::endl; }
};

int main()
{
	std::shared_ptr<PopupMenu> rootmenu = std::make_shared<PopupMenu>("ROOT");

	std::shared_ptr<MenuItem> p1 = std::make_shared<MenuItem>("메뉴1", 11, &foo);
	std::shared_ptr<MenuItem> p2 = std::make_shared<MenuItem>("메뉴2", 12, std::bind(&goo, 12));
	std::shared_ptr<MenuItem> p3 = std::make_shared<MenuItem>("메뉴3", 13, std::bind(&goo, 13));
	std::shared_ptr<MenuItem> p4 = std::make_shared<MenuItem>("메뉴4", 14);
	std::shared_ptr<MenuItem> p5 = std::make_shared<MenuItem>("메뉴5", 15);

	Camera cam;
	p4->setHandler( std::bind(&Camera::take, &cam, 1, 2) ); //메뉴 선택 : cam.take(1,2) 

	p5->setHandler( []() { std::cout << "lambda event handler" << std::endl; } );



	rootmenu->addMenu(p1);
	rootmenu->addMenu(p2);
	rootmenu->addMenu(p3);
	rootmenu->addMenu(p4);
	rootmenu->addMenu(p5);

	rootmenu->command();

}



