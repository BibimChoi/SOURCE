// 1_Command - 172 page
#include <iostream>
#include <vector>
#include <stack>

class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }
};
//------------------------------
struct ICommand
{
	virtual void Execute() = 0;
	virtual bool CanUndo() { return false; }
	virtual void Undo() {}
	virtual ~ICommand() {}
};
// 도형을 추가하는 명령은 공통의 특징이 많습니다.
// 기반 클래스로 제공합니다.

class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void Execute() override { v.push_back(CreateShape()); }
	bool CanUndo() override { return true; }
	void Undo() override
	{
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
	virtual Shape* CreateShape() = 0;
};

class AddRectCommand : public AddCommand
{
public:
	using AddCommand::AddCommand; 

	Shape* CreateShape() override { return new Rect; }
};

class AddCircleCommand : public AddCommand
{
public:
	using AddCommand::AddCommand; 

	Shape* CreateShape() override { return new Circle; }
};


class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void Execute() override
	{
		for (auto p : v) p->Draw();
	}
	bool CanUndo() override { return true; }
	void Undo() override
	{
		system("cls");
	}
};

// 여러개의 명령을 보관했다가 실행할수 있는 매크로를 만들어 봅시다.
class MacroCommand : public ICommand   // !! Composite 패턴을 사용한 복합객체 만들기
{
	std::vector<ICommand*> v;
public:
	void addCommand(ICommand* p) { v.push_back(p); }

	void Execute()
	{
		// 보관 중이던 모든 명령 실행.
		for (auto p : v)
			p->Execute();
	}
};


int main()
{
	std::vector<Shape*> v;

	MacroCommand* mc1 = new MacroCommand;

	mc1->addCommand(new AddRectCommand(v));
	mc1->addCommand(new AddCircleCommand(v));
	mc1->addCommand(new DrawCommand(v));
//	mc1->Execute(); // 등록된 모든 명령을 한번에 실행

	MacroCommand* mc2 = new MacroCommand;

	mc2->addCommand(new AddRectCommand(v));
	mc2->addCommand( mc1 );




	std::stack<ICommand*> cmd_stack;

	ICommand* pCmd;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			pCmd = new AddRectCommand(v);
			pCmd->Execute();
			cmd_stack.push(pCmd);
		}
		else if (cmd == 2)
		{
			pCmd = new AddCircleCommand(v);
			pCmd->Execute();
			cmd_stack.push(pCmd);
		}
		else if (cmd == 9)
		{
			pCmd = new DrawCommand(v);
			pCmd->Execute();
			cmd_stack.push(pCmd);
		}
		else if (cmd == 0)
		{
			if (cmd_stack.empty() == false)
			{
				pCmd = cmd_stack.top();
				cmd_stack.pop();

				if (pCmd->CanUndo())
					pCmd->Undo();

				delete pCmd;
			}
		}

	}
}
