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

	// 모든 도형은 자신의 복사본을 만들수 있어야 한다.
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
	MAKE_SINGLENTON(ShapeFactory)

	std::map<int, Shape*> prototype_map; 
public:
	void Register(int key, Shape* p)
	{
		prototype_map[key] = p; // 맵에.. 각 제품의 견본품을 보관합니다.
								// 견본을 복사해서 객체를 생성 => "Prototype 패턴"
	}
	Shape* Create(int type)
	{
		Shape* p = nullptr;

		if (prototype_map[type] != nullptr)
		{
			p = prototype_map[type]->Clone(); // 견본을 복사해서 객체 생성
		}
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 아래 코드는 공장에 "클래스"를 등록하는 개념입니다.
	//factory.Register(1, &Rect::Create);
	//factory.Register(2, &Circle::Create);

	// 공장에 클래스가 아닌 객체(견본품)을 등록해 봅시다.

	Rect* redRect  = new Rect; // 빨간색 크기가 5라고 가정
	Rect* blueRect = new Rect; // 파란색 크기가 10라고 가정
	Circle* redCircle = new Circle; //빨간색 원

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


