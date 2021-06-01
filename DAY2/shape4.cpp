#include <iostream>
#include <vector>

// 8. 코드 정리

// 예외로 사용할 클래스
class error_not_implementation : public std::exception
{
};

class Shape
{
protected:
	Shape() {}			// protected 생성자
	virtual ~Shape() {} // 가상 소멸자

protected:
	virtual void DrawImp() = 0; // 파생 클래스에게 반드시 만들어야 한다고 지시

public:
	void Draw()
	{
		std::cout << "mutex lock" << std::endl;
		DrawImp();
		std::cout << "mutex unlock" << std::endl;
	}
	
//	virtual Shape* Clone() = 0; // 파생 클래스가 반드시 만들어야 한다. 이렇게해도 좋고
	virtual Shape* Clone()
	{
		throw error_not_implementation();
		
		// 1. 파생 클래스가 재정의 안했고, Clone() 함수를 사용하지도 않았다- ok
		// 2. ""                         Clone() 함수 사용 => 예외 발생
		// 3. 파생 클래스가 재정의하면 ok.
	}
};





class Rect : public Shape
{
public:
	void DrawImp() override { std::cout << "Draw Rect" << std::endl; }

	// 가상 함수 재정의시 리턴 타입을 변경할수 있습니다.
	// 단, 상속관계의 타입으로만 됩니다. ( int* Clone() 등은 안됩니다.)
	Rect* Clone() override { return new Rect(*this); }
};

// Rect* r1 = new Rect;
// Rect* r2 = r1->Clone(); // 


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

		// 생각해볼 문제 1. 객체의 생성과정을 OCP를 만족하게 할수 없을까 ?
		//		 팩토리 패턴을 사용하면 됩니다. - 다음주 수요일 정도!!

		// 생각해볼 문제 2. Undo/Redo 를 넣으려면 어떻게 해야 할까 ?
		//		Command 패턴을 사용하면 됩니다. - 다음주 수요일 정도!!
		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);


		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복사할까요 >> ";
			int k;
			std::cin >> k;
			v.push_back(v[k]->Clone()); // 다형성 : OCP 만족
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw();	// 다형성 : OCP 만족
		}
	}
}





