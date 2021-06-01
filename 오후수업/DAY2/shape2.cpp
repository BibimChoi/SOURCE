#include <iostream>
#include <vector>

// 5. 다형성과 OCP

//    다형성(가상함수 기반 코드)는 OCP를 만족하는 아주 좋은 코딩입니다.




class Shape
{
public:
	int type;
	virtual void Draw() { std::cout << "Draw Shape" << std::endl; }

	// 자신의 복사본을 만드는 가상함수는 항상 유용하게 사용됩니다.
	virtual Shape* Clone() { return new Shape(*this); }
};



class Rect : public Shape
{
public:
	Rect() { type = 1; }
	void Draw() override { std::cout << "Draw Rect" << std::endl; }

	Shape* Clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	Circle() { type = 2; }
	void Draw() override { std::cout << "Draw Circle" << std::endl; }

	Shape* Clone() override { return new Circle(*this); }
};

class Triangle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Triangle" << std::endl; }
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

			// k 번째 도형의 복사본을 만들어서 v의 끝에 추가합니다.
			// 어떻게 구현해야 할까요 ?
			// k 번째 만든 도형이 뭘까요 ?

			v.push_back( v[k]->Clone() ); // ok.. 다형성..
										// OCP를 만족합니다.
										// 새로운 도형이 추가되어도 이 코드는 
										// 수정되지 않습니다.



			// type 에 따라 switch~case 문 사용
			// 아래 코드는 새로운 도형이 추가되면 코드가 수정(추가)되게 됩니다.
			// OCP를 만족하지 못하는 안 좋은 스타일 입니다.
			/*
			switch (v[k]->type)
			{
			case 1: v.push_back(new Rect( *v[k] )); break;
			case 2: v.push_back(new Circle(*v[k])); break;
			}
			*/

		}







		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw();	// 다형성(Polymorphism )
							// 동일한 함수 호출 표현식이 
							// 상황(객체) 에 따라 다르게 동작하는 것

			// 객체지향의 3가지 특징 : 캡슐화, 상속성, 다형성
		}
	}
}




