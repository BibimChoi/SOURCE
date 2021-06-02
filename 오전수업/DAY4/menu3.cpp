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

	}
};





int main()
{
	MenuItem m1("색상변경", 11);  
	m1.command();  
}


