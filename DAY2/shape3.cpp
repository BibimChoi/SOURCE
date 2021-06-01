#include <iostream>
#include <vector>

// 7. template method 패턴 : 변하지 않은 전체 흐름을 기반 클래스가 제공하고
//					변해야 하는 것만 가상함수(protected 또는 private) 로 해서
//					파생 클래스가 변경할수 있게 한다.


class Shape
{
public:

	// 공통성과 가변성의 분리
	// 변하지 않은 흐름 안에 있는 변하는 코드는 분리 되어야 한다.
	// 변해야 하는 부분을 찾아서 가상함수로 분리해라!!

protected:
	virtual void DrawImp()
	{
		std::cout << "Draw Shape" << std::endl; 
	}

public:
	void Draw() 
	{ 
		std::cout << "mutex lock" << std::endl;
		DrawImp();
		std::cout << "mutex unlock" << std::endl;
	}


	virtual Shape* Clone() { return new Shape(*this); }
};





class Rect : public Shape
{
public:
	void DrawImp() override { std::cout << "Draw Rect" << std::endl; }

	Shape* Clone() override { return new Rect(*this); }
};
class Circle : public Shape
{
public:
	void DrawImp() override { std::cout << "Draw Circle" << std::endl; }
	Shape* Clone() override { return new Circle(*this); }
};

class Triangle : public Shape
{
public:
	void DrawImp() override { std::cout << "Draw Triangle" << std::endl; }
	Shape* Clone() override { return new Triangle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);



		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복사할까요 >> ";
			int k;
			std::cin >> k;

			v.push_back(v[k]->Clone()); 
		}




		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw();
		}
	}
}









