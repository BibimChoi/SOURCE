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

// 도형을 추가하는 명령은 공통의 특징이 있습니다.
// 공통의 특징은 기반 클래스를 만들어서 제공하면 편리합니다
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
	// template method 패턴 입니다....
	// 그런데, 변하는 가상함수가 하는 일이 어떤 타입의 객체를 만들지 결정한다면
	// "Factory method" 라고도 합니다.
	// "Factory method" : 객체를 만들기 위한 인터페이스를 정의 하지만
	//				어떤 객체를 만들지는 파생클래스가 결정한다.	
	virtual Shape* CreateShape() = 0;
};

// factory class  : 객체를 만드는 역활을 하는 클래스
// factory method : 객체를 만드는 가상함수 - 어떤 타입의 객체인지는 파생 클래스가 결정


// 사각형을 추가하는 명령
class AddRectCommand : public AddCommand
{
public:
	using AddCommand::AddCommand;  // 생성자 상속 ( 인자로 vector를 가지는 생성자가필요)

	Shape* CreateShape() override { return new Rect; }
};

class AddCircleCommand : public AddCommand
{
public:
	using AddCommand::AddCommand; 

	Shape* CreateShape() override { return new Circle; }
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


