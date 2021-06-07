#include <iostream>
#include <string>
#include <vector>
using namespace std;



// 아래 클래스가 이미 있었다가 가정해 봅시다.

class TextView
{
	string data;
public:
	TextView(string s) : data(s) {}

	void Show() { cout << data << endl; } // 문자열을 이쁘게 화면 출력
};

//---------------------------------


class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}
};
class Rect : public Shape
{
public:
	void Draw() override { cout << "Draw Rect" << endl; }
};
class Circle : public Shape
{
public:
	void Draw() override { cout << "Draw Circle" << endl; }
};

// 도형편집기 시스템에서 "사각형, 원" 뿐 아니라 "글자" 도 관리하고 싶다.

// 이미 존재하던 TextView를 사용할수 있을까 ?

// 시스템 요구사항 : 1. Shape로 부터 상속 받아야 한다.
//                  2. Draw() 함수가 있어야 한다.

// "Adapter 패턴" : 기존 클래스의 인터페이스(함수 이름)을 변경해서
//					시스템이 요구하는 클래스를 만드는 것.
//					"인터페이스의 불일치를 해결"

// 클래스 어답터 : 클래스의 인터페이스 변경
// 객체   어답터 : 객체의   인터페이스 변경
class Text : public TextView, public Shape
{
public:
	Text(std::string s) : TextView(s) {}

	void Draw() override { TextView::Show(); }
};
int main()
{
	vector<Shape*> v;

	Text t("Hello");

	v.push_back(&t);

	v[0]->Draw();
}










