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

class RegisterShape
{
public:
	RegisterShape(int key, Shape*(*f)())
	{
		ShapeFactory& factory = ShapeFactory::getInstance();

		factory.Register(key, f);
	}
};


// 새로운 도형을 만들때 지켜야 하는 규칙을 매크로 로 제공하면 편리합니다.

#define REGISTER_SHAPE(classname)						\
	static Shape* Create() { return new classname; }	\
	static RegisterShape rs;


#define REGISTER_IMPEMENT(key, classname)				\
	RegisterShape classname::rs(key, &classname::Create);


class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }

	REGISTER_SHAPE(Rect)
};
REGISTER_IMPEMENT(1, Rect)


class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }

	REGISTER_SHAPE(Circle)
};
REGISTER_IMPEMENT(2, Circle)

// Triangle 만들어 보세요(3번으로)

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


