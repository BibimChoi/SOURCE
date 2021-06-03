// 메뉴이벤트3.cpp - 메뉴이벤트1 복사해오세요

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
//-----------------------------
// 방법 2. 변하는 것을 다른 클래스로
// 메뉴 이벤트를 처리하고 싶은 모든 클래스는 아래 인터페이스를 구현해야 한다.
struct IMenuListener
{
	// 이 디자인은 반드시 OnCommand가 메뉴의 ID를 받아야 한다.
	virtual void OnCommand(int id) = 0;
	virtual ~IMenuListener() {}
};

class MenuItem : public BaseMenu
{
	int id;

	IMenuListener* pListener = nullptr;
public:
	void setMenuListener(IMenuListener* p) { pListener = p; };

	MenuItem(std::string s, int n) : BaseMenu(s), id(n) {}

	void command() override
	{
		// 메뉴가 선택되었다는 사실을 등록된 객체에게 알려준다.
		if (pListener) pListener->OnCommand(id);

	}
};

//-----------------------
// 메뉴를 처리하고 싶은 클래스는 반드시 IMenuListener 를 구현해야 한다.
class Camera : public IMenuListener
{
public:

	void OnCommand(int id) override
	{
		std::cout << "메뉴 핸들러 작성" << std::endl;

		switch (id)
		{
			// id 에 따라서 기능 수행.
		}
	}
};

int main()
{
	Camera cam;
	std::shared_ptr<MenuItem> p1 = std::make_shared<MenuItem>("RED", 11);
	std::shared_ptr<MenuItem> p2 = std::make_shared<MenuItem>("BLUE", 12);

	p1->setMenuListener(&cam);
	p2->setMenuListener(&cam);

	p1->command();
	p2->command();
}



