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
//---------------------------
// 방법 1. 변하는 것을 가상함수로!!
// => 메뉴마다 클래스 한 개씩 만들어야 합니다.
// => 메뉴가 100개면 파생 클래스가 100개가 됩니다. 파생 클래스 많아 집니다.

// 어제 GUI 예제도 가상함수로 이벤트를 처리합니다.(LBD, KEYDOWN)
// => 주 윈도우는 1~2개 정도만 만들게 되므로.. 파생클래스가 많아지는 것은 아닙니다.


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(std::string s, int n) : BaseMenu(s), id(n) {}

	void command() override
	{
		OnCommand();
	}
	// 가상함수의 의미 : 변경하려면 파생 클래스를 만들라는 것!
	virtual void OnCommand() {}
};
// 각 메뉴 마다 파생클래스를 설계한다.
class RedMenu : public MenuItem
{
public:
	using MenuItem::MenuItem; // 기반 클래스의 생성자를 상속해 달라

	void OnCommand() override { std::cout << "Red Menu" << std::endl; }
};

class BlueMenu : public MenuItem
{
public:
	using MenuItem::MenuItem; 

	void OnCommand() override { std::cout << "Blue Menu" << std::endl; }
};

int main()
{
	std::shared_ptr<MenuItem> p1 = std::make_shared<RedMenu>("RED", 11); // new RedMenu("RED", 11)
	std::shared_ptr<MenuItem> p2 = std::make_shared<BlueMenu>("BLUE", 12);

	p1->command();
	p2->command();
}



