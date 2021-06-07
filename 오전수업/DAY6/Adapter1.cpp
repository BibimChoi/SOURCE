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

	void Show() { cout << data << endl; }
};



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

// 도형편집기 에서 사각형, 원 뿐 아니라, 문자열도 다루고 싶습니다
// 도형편집기에 새로운 도형이 추가되려면
// 1. Shape 로 부터 파생 되어야 한다.
// 2. Draw() 함수가 있어야 한다.

// TextView 를 도형편집기에서 사용할수 있도록 "인터페이스(함수이름)"을 변경하는 도구

// Adapter(어답터)패턴 : 기존 클래스의 인터페이스를 변경해서
//						시스템이 요구하는 인터페이스를 제공하는 것.
//						"인터페이스의 불일치를 해결하는 패턴"

// 클래스 어답터 : 클래스 인터페이스 변경
// 객체   어답터 : 객체의 인터페이스 변경
class Text : public TextView, public Shape
{
public:
	Text(std::string s) : TextView(s) {}

	// Show() 함수를 Draw()라는 이름으로 변경하는 부분
	void Draw() override { TextView::Show();  } // 기반 클래스 기능 사용
};

int main()
{
	vector<Shape*> v;

	Text t("Hello");
	v.push_back(&t); // Text 덕분에 TextView의 모든 기능을 도형편집기에서 사용가능
	
	v[0]->Draw();
}







