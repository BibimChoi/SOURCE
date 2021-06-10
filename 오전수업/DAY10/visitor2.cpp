#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem;
class PopupMenu;

// 새로운 메뉴가 추가되는 순간.. 방문자 인터페이스가 변경됩니다.
// 그동안 만들었던 모든 방문자는 수정되어야 합니다.
struct IMenuVisitor
{
	virtual void Visit(MenuItem* p) = 0;
	virtual void Visit(PopupMenu* p) = 0;
//	virtual void Visit(SpecialMenu* p) = 0;
	virtual ~IMenuVisitor() {}
};

struct IAcceptor
{
	virtual void Accept(IMenuVisitor*) = 0;
	virtual ~IAcceptor() {}
};

class BaseMenu : public IAcceptor
{
	std::string title;
public:

	void setTitle(std::string s) { title = s; }
	std::string getTitle() const { return title; }


	BaseMenu(std::string s) : title(s) {}

	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	void Accept(IMenuVisitor* p)
	{
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
		p->Visit(this);

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

			int sz = v.size(); 

			for (int i = 0; i < sz; i++)
			{
				printf("%d. %s\n", i + 1, v[i]->getTitle().c_str());
			}

			printf("%d. 상위메뉴로 이동\n", sz + 1);

			printf("메뉴를 선택하세요 >>");
			int cmd;
			std::cin >> cmd;


			if (cmd < 1 || cmd > sz + 1) 
				continue;

			if (cmd == sz + 1) 
				break;

			v[cmd - 1]->command(); 

		}
	}
};

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

	// Title을 변경하기 위해 BaseMenu 에 함수를 추가하면
	// 모든 하위 메뉴가 변경되어야 하지만..
	// 아래 처럼 방문자를 사용하면 기존 클래스는 변경되지 않습니다.
	TitleChangeVisitor tcv; 
	menubar->Accept(&tcv);

//	MenuColorChangeVisitor mccv;
//	menubar->Accept(&mccv);

	menubar->command();
}
