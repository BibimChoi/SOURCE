// 2_메뉴2
#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 




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
	MenuItem m("색상변경", 11); 

	m.command();
}



