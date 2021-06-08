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

// 모든 명령의 인터페이스
struct ICommand
{
	virtual void Execute() = 0;
	virtual bool CanUndo() { return false; }
	virtual void Undo() {}
	virtual ~ICommand() {}
};

// 사각형을 추가하는 명령
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void Execute() override { v.push_back(new Rect); }
	bool CanUndo() override { return true; }
	void Undo() override
	{
		Shape* s = v.back();
		v.pop_back();

		delete s;
	}
};

class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	void Execute() override { v.push_back(new Circle); }
	bool CanUndo() override { return true; }
	void Undo() override
	{
		Shape* s = v.back();
		v.pop_back();

		delete s;
	}
};
// vector가 가진 모든 도형을 그리는 명령
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
	
	std::stack<ICommand*> cmd_stack; // 모든 명령을 보관할 stack

	ICommand* pCmd;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) 
		{
			// 사각형을 추가하는 명령 객체를 만들어서 사용
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

	}
}


