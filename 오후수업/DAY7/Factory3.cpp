#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include "helper.h"

class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		typedef Shape*(*CREATE_FUNCTION)();

	std::map<int, CREATE_FUNCTION> create_map;
public:
	void Register(int key, CREATE_FUNCTION f)
	{
		create_map[key] = f;
	}
	Shape* Create(int type)
	{
		Shape* p = nullptr;

		if (create_map[type] != nullptr)
		{
			p = create_map[type]();
		}
		return p;
	}
};

// 도형을 공장에 자동으로 등록할때 사용할 클래스
class RegisterShape
{
public:
	RegisterShape( int key, Shape*(*f)() )
	{
		ShapeFactory& factory = ShapeFactory::getInstance();

		factory.Register(key, f);
	}
};
// main 함수 보다 전역변수의 생성자가 먼저 호출됩니다.
// 아래 코드의 결과를 생각해보세요
// RegisterShape rs(1, &Rect::Create);

class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }

	// static 멤버 데이타의 특징을 잘 생각해 보세요
	// 1. 모든 객체가 공유
	// 2. Rect 객체가 한개도 없어도 static 멤버 데이타(rs)는 메모리에 있습니다
	//    rs의 생성자는 main 함수가 실행되기 전에 이미 호출되었습니다.
	static RegisterShape rs;
};

RegisterShape Rect::rs(1, &Rect::Create);










class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }

	static RegisterShape rs;
};

RegisterShape Circle::rs(2, &Circle::Create);


int main()
{
	std::vector<Shape*> v;
	ShapeFactory& factory = ShapeFactory::getInstance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7)
		{
			Shape* p = factory.Create(cmd);

			if (p != nullptr)
				v.push_back(p);
		}

		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw();
		}

	}
}


