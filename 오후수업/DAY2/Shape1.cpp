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
class Shape
{
};
class Rect : public Shape
{
public:
	void Draw() { std::cout << "Draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void Draw() { std::cout << "Draw Rect" << std::endl; }
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
// 위 코드는 왜 에러일까요 ?
