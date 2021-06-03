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
class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(std::string s, int n) : BaseMenu(s), id(n) {}

	void command() override
	{
		// 메뉴 선택시 해야할 작업을 수행해야 한다
		// 그런데,, 여기서 직접 하게 되면 모든 메뉴가 동일한 작업을 하게 된다.
		
		// 메뉴에 따라 다른 작업을 하게 해야 한다.
	}
};

int main()
{
	std::shared_ptr<MenuItem> p1 = std::make_shared<MenuItem>("RED",  11);
	std::shared_ptr<MenuItem> p2 = std::make_shared<MenuItem>("BLUE", 12);

	p1->command();
	p2->command();
}







