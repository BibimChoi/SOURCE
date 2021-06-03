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
// 방법 3. 메뉴 선택시 등록된 함수를 직접 호출(함수 포인터 개념사용)
// => 그런데, C++ 에는 모든 종류의 함수(일반함수, 멤버함수)의 주소를 담는
//    일반화된 함수 포인터가 없습니다.!!
//    그래서 이기술이 쉽지 않았습니다(C++11 이전까지는.. C++11 부터는 bind와 function 사용)

// 참고 : C# delegate, Objective-c(swift) Selector 라는 기술이 범용적인 함수 포인터 기술입니다.

class MenuItem : public BaseMenu
{
	int id;

	void(*handler)() = nullptr; // 이렇게 하면 일반 함수만 연결가능합니다.

	// 멤버 함수가 연결되려면 아래 처럼 해야 합니다.
	void(Camera::*handler)();
	Camera* target;  // 멤버 함수뿐 아니라 객체도 알아야 합니다.

public:
	void setHandler( void(*f)() ) { handler = f; }

	MenuItem(std::string s, int n) : BaseMenu(s), id(n) {}

	void command() override
	{
		// 등록된 핸들러 함수 호출
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







