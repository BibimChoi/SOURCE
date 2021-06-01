#include <iostream>
#include <vector>

// 9. 코드 정리!!

// 예외 클래스 만들기
class error_not_implementation : public std::exception {};

class Shape
{
protected:
	Shape() {}	       // Shape는 객체생성될 필요 없다.
	virtual ~Shape() {}// 기반클래스는 가상소멸자 필요

protected:
	virtual void DrawImp() = 0; // 모든 도형은 반드시 이 가상함수를 만들어야 한다.

public:
	void Draw()
	{
		std::cout << "mutex lock" << std::endl;
		DrawImp();
		std::cout << "mutex unlock" << std::endl;
	}

//	virtual Shape* Clone() = 0; // 이 코드도 좋고

	// 아래 처럼 하는 경우도 있습니다.
	// 1. 파생 클래스가 재정의 하지 않고, 사용도 하지 않으면 - ok
	// 2. ""						  , 사용하면 - 예외 발생
	// 3. 재정의 하면 ok.
	virtual Shape* Clone() { throw error_not_implementation(); }
};


class Rect : public Shape
{
public:
	void DrawImp() override { std::cout << "Draw Rect" << std::endl; }

	// 가상 함수 재정의시 리턴 타입 변경가능합니다.
	// 단, 상속계층의 타입으로만 변경됩니다.(아래 코드에서 int* 로하면 에러입니다)
	Rect* Clone() override { return new Rect(*this); }
};

//Rect* r1 = new Rect;
//Rect* r2 = r1->Clone(); // 이 코드가 될까요 ?



class Circle : public Shape
{
public:
	void DrawImp() override { std::cout << "Draw Circle" << std::endl; }

	Circle* Clone() override { return new Circle(*this); }
};

class Triangle : public Shape
{
public:
	void DrawImp() override { std::cout << "Draw Triangle" << std::endl; }
	Triangle* Clone() override { return new Triangle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// 생각해 볼 문제 1. 객체의 생성을 OCP를 만족하게 할수 없을까 ?
		//					새로운 도형이 추가되어도 아래 코드가 변경되지 않게 !!
		// => 팩토리 패턴을 알면 됩니다. - 다음주 화 또는 수요일에 해결


		// 생각해 볼 문제 2. Undo/Redo 기능을 넣으려면 어떻게 해야 할까 ?
		// =>  Command 라는 이름의 패턴을 알면 됩니다. - 다음주 화또는 수요일에..

		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);



		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복사할까요 >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->Clone()); // 다형성 기반, OCP만족
		}

		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw();	// 다형성기반 이므로 OCP만족, 새로운 도형추가되어도
							// 코드 변화 없음
		}
	}
}




