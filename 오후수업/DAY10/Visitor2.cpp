#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem;
class PopupMenu;


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

	// 메뉴의 색상을 변경하는 가상함수를 추가한다고 가정해 봅시다.
//	virtual void changeColor() = 0; // popupmenu, menuitem 모두 수정되어야 합니다.
									// 어려워 집니다.
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
// 결론 : 가상함수를 직접 추가하는 것은 어렵지만
//        가상함수가 할일을 방문자로 설계하는 것은 쉽습니다.
// 메뉴의 타이틀 색상을 변경하는 방문자.
class TitleColorChangeVisitor : public IMenuVisitor
{
public:
	// 메뉴에 종류에 따라 타이틀 색상을 변경하는 코드 작성
	void Visit(MenuItem* p) {} 
	void Visit(PopupMenu* p){}
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

	TitleChangeVisitor tcv; 
	menubar->Accept(&tcv);

	TitleColorChangeVisitor tccv;
	menubar->Accept(&tccv);

	menubar->command();
}
