#include <iostream>
#include <vector>
#include <stack>
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
};
class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }
};

// 도형을 만드는 공장
class ShapeFactory
{
	MAKE_SINGLETON( ShapeFactory )
public:
	Shape* Create(int type)
	{
		Shape* p = nullptr;

		switch (type)
		{
		case 1: p = new Rect; break;
		case 2: p = new Circle; break;
		}
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7) // 1~7번은 도형의 번호로 예약
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


