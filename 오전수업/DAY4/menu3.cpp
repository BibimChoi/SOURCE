// 2_메뉴3
#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// "Composite" 패턴

// 1. "복합객체(PopupMenu) 는 개별객체(MenuItem) 뿐 아니라 복합객체 자신도 보관한다."
//    => 복합객체와 개별객체는 공통의 기반 클래스가 필요 하다.(BaseMenu)

// 2. 복합객체와 개별객체는 사용법이 동일시 된다.(선택시 모두 command() 호출)
//    => command() 는 반드시 BaseMenu 안에 있어야 한다.

// 특징 : 객체의 포함관계가 "Tree 구조"를 나타낸다.
//		  마지막 자식이 개별객체가 된다.

// 모든 메뉴의 기반 클래스
class BaseMenu
{
	std::string title;
public:
	BaseMenu(std::string s) : title(s) {}

	std::string getTitle() const { return title; }

	virtual void command() = 0;
};

// MenuItem
class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(std::string s, int n) : BaseMenu(s), id(n) {}

	void command() override
	{
		std::cout << getTitle() << " 메뉴가 선택됨" << std::endl;
		_getch(); // 잠시 정지
	}
};
// github.com/codenuri/SOURCE  오전수업/DAY4/menu3.cpp 

class PopupMenu : public BaseMenu
{
	std::vector< BaseMenu* > v; // 핵심
public:
	PopupMenu(std::string s) : BaseMenu(s) {}

	void addMenu(BaseMenu* p) { v.push_back(p); }

	// 팝업메뉴 선택시...
	void command() override
	{
		while (1)
		{
			system("cls");
			int sz = v.size(); // 하위 메뉴 갯수

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->getTitle() << std::endl;
			}
			std::cout << sz + 1 << ". 상위 메뉴로 이동" << std::endl;

			int cmd;
			std::cout << "메뉴를 선택해 주세요 >> ";
			std::cin >> cmd;

			if (cmd == sz + 1)  // 상위 메뉴로 이동선택
				break; // 루프 탈출

			if (cmd < 1 || cmd > sz + 1) // 잘못된 입력
				continue;

			// 선택된 메뉴를 실행합니다. 
			v[cmd - 1]->command(); // 다형성
								// 어떤 메뉴인지 조사할필요 없습니다.
		}
	}
};

int main()
{
	PopupMenu* menubar = new PopupMenu("MENUBAR");
	PopupMenu* p1 = new PopupMenu("색상 변경");
	PopupMenu* p2 = new PopupMenu("해상도 변경");

	menubar->addMenu(p1);
	menubar->addMenu(p2);

	p1->addMenu(new MenuItem("RED",   11));
	p1->addMenu(new MenuItem("GREEN", 12));
	p1->addMenu(new MenuItem("BLUE",  13));

	p2->addMenu(new MenuItem("HD",  21));
	p2->addMenu(new MenuItem("FHD", 22));
	p2->addMenu(new MenuItem("UHD", 23));

	// 메뉴를 시작하려면 ??
	menubar->command();
}







