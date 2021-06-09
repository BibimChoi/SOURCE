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

	void Execute() override { v.push_back( CreateShape() ); }
	bool CanUndo() override { return true; }
	void Undo() override
	{
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
	// Template method 의 전형적인 모양입니다.
	// 그런데, 변해야 하는 가상함수 가 하는일이 어떤 타입의 객체인지를 결정한다면..
	// "Factory method" 라고도 합니다.
	virtual Shape* CreateShape() = 0;				
};

class AddRectCommand : public AddCommand
{
public:
	using AddCommand::AddCommand; // 생성자 상속

	Shape* CreateShape() override { return new Rect; }
};

class AddCircleCommand : public AddCommand
{
public:
	using AddCommand::AddCommand; // 생성자 상속

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







int main()
{
	std::vector<Shape*> v;

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
