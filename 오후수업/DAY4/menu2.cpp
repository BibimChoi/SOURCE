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

	// 모든 종류의 메뉴는 선택될수 있습니다 - 핵심!!
	// 구현은 파생 클래스에서!!!
	virtual void command() = 0;
};

// MenuItem
class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem( std::string s,  int n) : BaseMenu(s), id(n) {}

	void command() override
	{
		std::cout << getTitle() << " 메뉴가 선택됨" << std::endl;

		_getch(); // 잠시 정지
	}
};

int main()
{
	MenuItem m("색상변경", 11); // 왜 에러일까요 ?
}




