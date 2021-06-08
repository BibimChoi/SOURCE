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

	// 자기 자신을 만드는 static 멤버 함수는 항상 유용하게 활용 됩니다.
	static Shape* Create() { return new Rect; }
};

// 객체를 만드는 법
// 1. Rect* p1 = new Rect;
// 2. Rect* p2 = Rect::Create();

/*
void foo(std::string type)
{
	// 함수인자에 따라 다른 도형(미래에 만들어질 도형 포함) 만들고 싶다.
	Shape* p = new type; // 말도 안된다!! 문자열로된 클래스 이름으로 객체를 만들수 없다.
}
foo("Rect");
foo("Circle");
*/
// 아래 처럼 만들면.. 미래에 만들어질 클래스도 객체 생성할수 있습니다.
/*
void foo( Shape*(*f)() )
{
	Shape* p = f(); // 인자로 전달된 함수로 객체 생성
}

foo(&Rect::Create);
foo(&Circle::Create);
foo(&Triangle::Create); // 나중에 추가된 Triangle의 객체를 예전에 만들어둔 foo에서
						// 객체 생성하는 코드..
*/






class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
};

class ShapeFactory
{
	MAKE_SINGLENTON(ShapeFactory)

	typedef Shape*(*CREATE_FUNCTION)();

	std::map<int, CREATE_FUNCTION> create_map; // 도형 번호:생성함수의 맵
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
			p = create_map[type](); // 맵에 등록된 함수로 객체 생성
		}
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 공장에 각 제품(도형)을 등록합니다.( 도형번호 , 생성함수)
	factory.Register(1, &Rect::Create);
	factory.Register(2, &Circle::Create);


	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7) // 1 ~ 7 을 도형의 번호로 사용하기로 미리 예약
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


