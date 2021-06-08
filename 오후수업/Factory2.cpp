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

class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }

	// 자신을 만드는 static 멤버 함수는 참 편리하고,, 유용합니다.!!
	static Shape* Create() { return new Rect; }
};
// Rect 객체를 만드는 2가지 방법
// 1. Rect* p1 = new Rect;
// 2. Rect* p2 = Rect::Create()

/*
// 인자에 따라 다른 도형을 만드는 함수를 생각해 봅시다.
// 만약, 새로운 도형이 추가된다면 ?? => 기존 코드를 수정해야 합니다.(if 문 추가)
void foo(int type)
{
	Shape* p = nullptr;
	if (type == 1) p = new Rect;
	if (type == 2) p = new Circle;
}
// goo 는 새로운 도형이 추가되어도 수정되지 않습니다.
void goo(Shape*(*f)())
{
	Shape* p = f();
}
// goo 호출시 어떤 도형을 만들지 정보를 전달합니다.
goo(&Rect::Create);
goo(&Circle::Create);
goo(&Triangle::Create);
*/






class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	typedef Shape*(*CREATE_FUNCTION)();
	
	std::map<int, CREATE_FUNCTION> create_map;  // 도형번호:생성함수 를 맵에 보관
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
			p = create_map[type](); // 생성함수를 사용해서 도형객체 생성
		}
		return p;
	}
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 공장에 제품(도형)을 등록 합니다.
	factory.Register(1, &Rect::Create);
	factory.Register(2, &Circle::Create);

	// 이제 새로운 도형이 추가되면 공장에 등록만 하고 사용하면 됩니다.


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


