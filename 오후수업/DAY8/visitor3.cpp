#include <iostream>
#include <string>
#include <vector>
#include <conio.h> // _getch() 사용위해..

// 복합객체의 형태 
// list와 같은 컨테이너 : 모든 요소가 동일한 타입
// Menu System         : 요소의 타입이 다르다.

// 메뉴 방문자의 인터페이스
class PopupMenu;
class MenuItem;

struct IMenuVisitor
{
	virtual void Visit(MenuItem* m) = 0;
	virtual void Visit(PopupMenu* m) = 0;
	virtual ~IMenuVisitor() {}
};

struct IAcceptor
{
	virtual void Accept(IMenuVisitor* p) = 0;
	virtual ~IAcceptor() {}
};



class BaseMenu : public IAcceptor
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
	void Accept(IMenuVisitor* p) override
	{
		// MenuItem 은 복합객체가 아니므로
		// 자신만 전달하면 된다.
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

	void Accept(IMenuVisitor* p) override
	{
		p->Visit(this); // 자신을 방문자에 보내고

		// 하위 메뉴에 방문자를 방문 시킨다.
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

// 이제 다양한 용도의 방문자만 설계하면 됩니다
// 방문자는 한개 메뉴에 대한 연산만 정의 하면 됩니다.
class PopupMenuTitleChangeVisitor : public IMenuVisitor
{
public:
	void Visit(MenuItem* m) override {}
	void Visit(PopupMenu* m) override 
	{
		std::string s = m->getTitle();

		s = "[ " + s + " ]";

		m->setTitle(s);
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

	// PopupMenu의 타이틀을 변경하는 방문자
	PopupMenuTitleChangeVisitor v;
	menubar->Accept(&v);


	// 시작하려면어떻게 할까요 ?
	menubar->command();
}







