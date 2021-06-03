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
//-------------------------
// 방법 3. 메뉴 선택시 등록된 함수 호출(함수 포인터 사용)
// => 문제점 : C++에는 모든 종류의 함수 주소를 담는 범용적인 함수 포인터가 없습니다.
//				C# 에는 "delegate" 라는 문법
//				Objective-C 와 swift에는 "selector" 라는 문법이
//				범용적인 함수포인터 입니다.

// C++은 C++11 부터 function 지원 합니다.

class MenuItem : public BaseMenu
{
	int id;

	// 아래 처럼 하면 일반 함수만 등록가능합니다
	void(*handler)() = nullptr;

	// 멤버 함수도 등록하려면 아래처럼 해야 합니다.
	void(Camera::*handler)() = nullptr;
	Camera* target; // 멤버 함수 포인터를 호출하려면 객체도 필요 합니다.
					// QT : signal/slot 에서 (객체, 함수)
					// 아이폰 : 타겟(객체)/액션(함수주소)
					// 그런데, 위처럼 하면 Camera만 됩니다.!!!
public:
	void  setHandler( void(*f)() ) { handler = f; }


	MenuItem(std::string s, int n) : BaseMenu(s), id(n) {}

	void command() override
	{
		// 등록된 함수 호출!
		if (handler) handler();
	}
};











int main()
{
	std::shared_ptr<MenuItem> p1 = std::make_shared<MenuItem>("RED", 11);
	std::shared_ptr<MenuItem> p2 = std::make_shared<MenuItem>("BLUE", 12);

	p1->command();
	p2->command();
}



