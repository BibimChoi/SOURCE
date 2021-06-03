#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <memory> // 스마트 포인터!

class BaseMenu
{
	std::string title;
public:
	BaseMenu(std::string s) : title(s) {}

	std::string getTitle() const { return title; }

	virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(std::string s, int n) : BaseMenu(s), id(n) {}

	void command() override
	{
		std::cout << getTitle() << " 메뉴가 선택됨" << std::endl;

		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector< std::shared_ptr<BaseMenu> > v; 
public:
	PopupMenu(std::string s) : BaseMenu(s) {}

	void addMenu( std::shared_ptr<BaseMenu>  p) { v.push_back(p); }

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


int main()
{
	std::shared_ptr<PopupMenu> menubar = std::make_shared<PopupMenu>("MENUBAR");

	std::shared_ptr<PopupMenu> p1 = std::make_shared<PopupMenu>("색상 변경");
	std::shared_ptr<PopupMenu> p2 = std::make_shared<PopupMenu>("해상도 변경");

	menubar->addMenu(p1);
	menubar->addMenu(p2);

	p1->addMenu(std::make_shared<MenuItem>("RED", 11));
	p1->addMenu(std::make_shared<MenuItem>("GREEN", 12));
	p1->addMenu(std::make_shared<MenuItem>("BLUE", 13));
	p1->addMenu(std::make_shared<MenuItem>("BLACK", 14));

	p2->addMenu(std::make_shared<MenuItem>("HD", 21));
	p2->addMenu(std::make_shared<MenuItem>("FHD", 22));
	p2->addMenu(std::make_shared<MenuItem>("UHD", 23));

	menubar->command();
}



