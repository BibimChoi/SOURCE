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

// 상속 vs 포함

// 상속 : 항상 클래스에 대해서 기능추가, 인터페이스 변경, 강한 결합(교체 불가능, template method)
// 포함 : 객체에 기능추가(Decorator), 객체인터페이스변경, 약한 결합(교체 가능, strategy)

// 클래스 어답터 : 클래스의 인터페이스 변경, (상속기반)
class Text : public TextView, public Shape
{
public:
	Text(std::string s) : TextView(s) {}

	void Draw() override { TextView::Show(); }
};

// 객체   어답터 : 객체의   인터페이스 변경, (포함 기반 )
class Text2 :public Shape
{
	TextView* ptv; // 외부에 이미 존재하는 TextView를 가르키게 합니다.
public:
	Text2(TextView* p) : ptv(p) {}

	void Draw() override { ptv->Show(); }
};

int main()
{
	vector<Shape*> v;

	TextView tv("Hello");	// TextView : 클래스,   tv : 객체 입니다.

//	v.push_back(&tv);		// 이미 존재하는 객체 tv를 v에 넣으려고 합니다.
							// error. Shape로 부터 파생 되어야 한다는 조건을 만족하지
							// 못합니다.
	Text2 t2(&tv); // tv 에 어답터를 끼웁니다( 110v 플러그에 돼지코 연결하듯..)

	v.push_back(&tv); // 기존 시스템에 연결합니다( 돼지코를 220v 에 연결)
}			










