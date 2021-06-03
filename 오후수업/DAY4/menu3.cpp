// 2_메뉴2
#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


// "Composite 패턴"

// 복합객체(PopupMenu) 는 개별객체(MenuItem) 뿐 아니라 복합객체 자신도 보관한다.

// => 복합객체와 개별객체는 공통의 기반 클래스가 필요 한다.


// 복합객체와 개별객체의 사용법이 동일시된다.(모두 선택시 command 호출)

// => command() 함수는 기반 클래스(BaseMenu)에 있어야 한다.



// 특징 : 객체의 포함관계가 tree 구조로 구성된다.



// 모든 메뉴의 기반 클래스
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
	std::vector<BaseMenu*> v; // 하위 메뉴들.. 핵심!!!
public:
	PopupMenu(std::string s) : BaseMenu(s) {}

	void addMenu(BaseMenu* p) { v.push_back(p); }

	// 아래 코드가 핵심입니다.
	// 팝업메뉴를 선택할때!!
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

			if (cmd == sz + 1) // "상위 메뉴로" 선택!!
				break;

			if (cmd < 1 || cmd > sz + 1) // 잘못된 입력
				continue;		// 다시 입력

			// 선택된 메뉴를 실행합니다.
			v[cmd - 1]->command(); // 다형성!!!
								   // MenuItem 인지 Popup 인지 조사할 필요 없다.
		}
	}
};


int main()
{
	PopupMenu* menubar = new PopupMenu("MENUBAR");
	PopupMenu* p1      = new PopupMenu("색상 변경");
	PopupMenu* p2      = new PopupMenu("해상도 변경");

	menubar->addMenu(p1);
	menubar->addMenu(p2);

	p1->addMenu(new MenuItem("RED",   11));
	p1->addMenu(new MenuItem("GREEN", 12));
	p1->addMenu(new MenuItem("BLUE",  13));

	p2->addMenu(new MenuItem("HD",  21));
	p2->addMenu(new MenuItem("FHD", 22));
	p2->addMenu(new MenuItem("UHD", 23));
	
	// 이제 시작하려면 ?
	menubar->command();
}



