// Command1 : 모든 명령을 객체화 해서 저장/복구 하는 개념
// Command2 : 각 클래스의 공통의 특징은 "기반 클래스를 만들어서 제공"
// Command3 : Composite 패턴으로 MacroCommand 만들기

// QT 라이브러리 안에 "UndoManager" 클래스가 있습니다


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

// Command : 프로그램에서 사용하는 모든 명령 을 객체화 한다.
//			명령의 저장/복구를 통해서 Undo/Redo 등의 기능을 구현할때 사용

// 모든 명령의 인터페이스
struct ICommand
{
	virtual void Execute() = 0;
	virtual bool CanUndo() { return false; }
	virtual void Undo() {}
	virtual ~ICommand() {}
};


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

// 사각형을 추가하는 명령
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

//-----------------
// 여러개의 명령을 한번에 실행하는 매크로를 제공해 봅시다.
class MacroCommand : public ICommand   // Composite 패턴.!!!
{
	std::vector<ICommand*> v;
public:
	void addCommand(ICommand* p) { v.push_back(p); }
	
	void Execute()
	{
		// 보관 중인 모든 명령 실행
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
//	mc1->Execute();


	MacroCommand* mc2 = new MacroCommand;
	mc2->addCommand(new AddRectCommand(v));
	mc2->addCommand(mc1);
	mc2->Execute();




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
				{
					pCmd->Undo();
				}

				delete pCmd;
			}
		}

	}
}


