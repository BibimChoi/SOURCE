// codexpert.org 에서 "DAY2.zip" 받으세요 ID : 메일 주소, 비밀번호 : 123456

// 압축 풀고 vs 에서 열면 됩니다.


// 1. "debug", "x86"

// 2. 프로젝트메뉴 => DAY2 속성 메뉴 선택후

//    Windows SDK 버전 과 플랫폼 도구 집합 버전 설정하세요











// 3_도형편집기 - 15 page
#include <iostream>
#include <vector>

// 1. 모든 도형을 타입으로 설계하면 편리하다.

// 2. 공통의 기반 클래스가 있다면 모든 도형을 묶어서 관리할수 있다.

// 3. 모든 도형의 공통의 특징은 "반드시 기반 클래스에도 있어야 한다."
//    그래야, 기반 클래스 포인터로 묶어서 사용할때 해당 기능을 사용할수 있다

// 4. 기반 클래스 함수중에서 파생 클래스가 재정의 하게 되는 것은 반드시 가상함수로 해야 한다.

//	  가상함수가 아닌 함수는 재정의 하지 말라! - effective - C++ 서적에 있는 격언


class Shape
{
public:
	virtual void Draw() { std::cout << "Draw Shape" << std::endl; }
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



int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw();
		}
	}
}
// github.com/codenuri/SOURCE 에서 소스 계속 update 해 놓겠습니다.
// 오후수업/DAY2/Shape1.cpp 에 지금 소스 있습니다.
