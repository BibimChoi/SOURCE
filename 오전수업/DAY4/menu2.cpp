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

	// 모든 메뉴는 선택될수 있다
	// 구현은 파생 클래스에서!!! 
	virtual void command() = 0; // 핵심
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

int main()
{
	MenuItem m1("색상변경", 11); // 왜 에러가 나올까요 ?
	m1.command(); // 사용자가 메뉴 선택
}




