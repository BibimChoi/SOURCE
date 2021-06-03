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
// 메뉴 이벤트 처리 방법 1. 변하는 것을 가상함수로!
// => 메뉴는 수십~수백개가 될수 있다.
// => 이 디자인은 파생 클래스의 갯수가 너무 많아 진다.

// 어제 배운 GUI의 경우도 가상함수로 처리하는 버전이 있지만
// 주 윈도우는 1~2개 정도만 만들게 되므로.. 파생 클래스가 많아 지지 않는다.

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(std::string s, int n) : BaseMenu(s), id(n) {}

	void command() override
	{
		OnCommand();
	}
	virtual void OnCommand() {}
};
// MenuItem 을 직접 사용하지말고 파생클래스를 만들라는 의미!!
class RedMenu : public MenuItem
{
public:
	using MenuItem::MenuItem; // 기반 클래스의 생성자를 상속해 달라.
	void OnCommand() { std::cout << "색상을 Red 로 변경" << std::endl; }
};

class BlueMenu : public MenuItem
{
public:
	using MenuItem::MenuItem;
	void OnCommand() { std::cout << "색상을 Blue 로 변경" << std::endl; }
};

int main()
{
	std::shared_ptr<MenuItem> p1 = std::make_shared<RedMenu>("RED", 11);
	std::shared_ptr<MenuItem> p2 = std::make_shared<BlueMenu>("BLUE", 12);

	p1->command();
	p2->command();
}







