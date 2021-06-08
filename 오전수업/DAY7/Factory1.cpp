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
// 아래 처럼 공장이 있으면.. 새로운 도형이 추가될때
// 1. 공장의 코드가 수정되어야 합니다.
// 2. 그런데, 여러곳이 아닌 공장 한곳만 수정하면 됩니다 - 코드 수정의 최소화
//    공장이 없다면, 도형 추가시 여러곳이 수정되어야 합니다.
class ShapeFactory
{
	MAKE_SINGLENTON(ShapeFactory)
public:
	Shape* Create(int type)
	{
		Shape* p = nullptr;

		switch (type)
		{
		case 1: p = new Rect;   break;
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


