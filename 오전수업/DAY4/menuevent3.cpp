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
// 메뉴 이벤트 처리 방법 2. 변하는 것을 다른 클래스로!!
// 메뉴 선택시.. 등록된 다른 클래스의 약속된 함수 호출

// 규칙 : 메뉴 이벤트를 처리하고 싶은 클래스는 아래 인터페이스를 구현해야 한다.
struct IMenuListener
{
	virtual void OnCommand(int id) = 0;
	virtual ~IMenuListener() {}
};

class MenuItem : public BaseMenu
{
	int id;
	IMenuListener* pListener = nullptr;
public:
	void setListener(IMenuListener* p) { pListener = p; }

	MenuItem(std::string s, int n) : BaseMenu(s), id(n) {}

	void command() override
	{
		// 메뉴가 선택된 사실을 등록된 객체의 약속된 함수를 통해서 전달
		if (pListener != nullptr) pListener->OnCommand(id);
	}
};

//---------------------
// 이제 메뉴 이벤트를 처리하고 싶은 클래스는 IMenuListener 인터페이스를 구현해야 합니다.
class Camera : public IMenuListener
{
public:
	void OnCommand(int id) override
	{
		std::cout << "메뉴 처리" << std::endl;

		switch (id)
		{
			// 메뉴 ID에 따라 해야할 일을 수행..
		}
	}
};

int main()
{
	Camera cam;
	std::shared_ptr<MenuItem> p1 = std::make_shared<MenuItem>("RED", 11);
	std::shared_ptr<MenuItem> p2 = std::make_shared<MenuItem>("BLUE", 12);

	p1->setListener(&cam);
	p2->setListener(&cam);

	p1->command();
	p2->command();
}







