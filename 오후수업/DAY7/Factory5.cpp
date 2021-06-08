// Factory5.cpp => Factory2 번 복사해 오세요

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

	// 모든 도형은 자신의 복사본을 생성할수 있어야 한다.
	virtual Shape* Clone() = 0;
};




class Rect : public Shape
{
public:
	Rect* Clone() override { return new Rect(*this); }

	void Draw() override { std::cout << "Draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }
};






class Circle : public Shape
{
public:
	Circle* Clone() override { return new Circle(*this); }

	void Draw() override { std::cout << "Draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map;
public:
	void Register(int key, Shape* sample)
	{
		prototype_map[key] = sample;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;

		if (prototype_map[type] != nullptr)
		{
			p = prototype_map[type]->Clone(); // 이렇게 객체를 생성하는 것을
											  // Prototype 패턴이라고 합니다.
		}
		return p;
	}
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 공장에 클래스를 등록하는 코드
//	factory.Register(1, &Rect::Create);
//	factory.Register(2, &Circle::Create);


	// 자주 사용되는 형태의 도형 객체를 만들고
	Rect* redRect = new Rect; // 빨간색 사각형이라고 가정
	Rect* blueRect = new Rect;
	Circle* redCircle = new Circle;

	// 공장에 자주 사용되는 객체의 견본(prototype)을 등록합니다.
	factory.Register(1, redRect);
	factory.Register(2, blueRect);
	factory.Register(3, redCircle);






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


