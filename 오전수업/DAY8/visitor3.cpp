#include <iostream>
#include <string>
#include <vector>
#include <conio.h> // _getch() 사용위해..

// 복합객체 : list      => 모든 요소가 같은 타입
//		     PopupMenu => 요소의 타입이 다르다.

// 메뉴에 들어갈 방문자의 인터페이스
// 핵심 :  요소의 타입이 다르므로 Visit 함수가 2개
class MenuItem;
class PopupMenu;
struct IMenuVisitor
{
	virtual void Visit(MenuItem* p) = 0;
	virtual void Visit(PopupMenu* p) = 0;
	virtual ~IMenuVisitor() {}
};

struct IAcceptor
{
	virtual void Accept(IMenuVisitor*) = 0;
	virtual ~IAcceptor() {}
};

class BaseMenu  : public IAcceptor
{
	std::string title;
public:

	void setTitle(std::string s) { title = s; }
	std::string getTitle() const { return title; }


	BaseMenu(std::string s) : title(s) {}


	// 모든 메뉴는 선택될수 있다.. 구현은 파생클래스에서!!
	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	// 방문자가 MenuItem 을 방문 할때 
	void Accept(IMenuVisitor* p)
	{
		// 방문자에게 자신만 보내면 된다.
		p->Visit(this);
	}


	MenuItem(std::string s, int n) : BaseMenu(s), id(n) {}

	virtual void command()
	{
		std::cout << getTitle() << " 선택됨" << std::endl;
		_getch();
	}
};



class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:

	void Accept(IMenuVisitor* p)
	{	
		// 자신을 보내고..
		p->Visit(this); 

		// 모든 하위 메뉴에 방문자를 전달한다.
		for (auto m : v)
			m->Accept(p); 
	}


	PopupMenu(std::string s) : BaseMenu(s) {}

	void addMenu(BaseMenu* p) { v.push_back(p); }

	virtual void command()
	{
		while (1)
		{
			system("cls");

			int sz = v.size(); // 하위 메뉴 갯수

			for (int i = 0; i < sz; i++)
			{
				printf("%d. %s\n", i + 1, v[i]->getTitle().c_str());
			}

			printf("%d. 상위메뉴로 이동\n", sz + 1);

			printf("메뉴를 선택하세요 >>");
			int cmd;
			std::cin >> cmd;


			if (cmd < 1 || cmd > sz + 1) // 잘못된 입력
				continue;

			if (cmd == sz + 1) // 상위 메뉴로 선택
				break;

			v[cmd - 1]->command(); // 다형성

		}
	}
};

// 팝업 메뉴의 타이틀을 변경하는 방문자
// 방문자는 한개 요소에 대해서만 연산하면 됩니다.
class TitleChangeVisitor : public IMenuVisitor
{
public:
	void Visit(MenuItem* p) {}

	void Visit(PopupMenu* p) 
	{
		std::string s = p->getTitle();

		s = "[ " + s + " ]";

		p->setTitle(s);
	}
};

int main()
{
	PopupMenu* menubar = new PopupMenu("MENUBAR");
	PopupMenu* p1 = new PopupMenu("색상 변경");
	PopupMenu* p2 = new PopupMenu("해상도 변경");

	menubar->addMenu(p1);
	menubar->addMenu(p2);

	p1->addMenu(new MenuItem("RED", 11));
	p1->addMenu(new MenuItem("GREEN", 12));
	p1->addMenu(new MenuItem("BLUE", 13));
	p1->addMenu(new MenuItem("BLACK", 14));

	p2->addMenu(new MenuItem("HD", 21));
	p2->addMenu(new MenuItem("FHD", 22));
	p2->addMenu(new MenuItem("UHD", 23));

	TitleChangeVisitor tcv; // 타이틀을 변경하는 방문자
	menubar->Accept(&tcv);

	// 시작하려면어떻게 할까요 ?
	menubar->command();
}







