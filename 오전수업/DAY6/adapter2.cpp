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

// 클래스 어답터 : 클래스 인터페이스 변경
//				  상속을 사용하게 됩니다. (상속은 항상 클래스에 대한 변경, 추가입니다.)
class Text : public TextView, public Shape
{
public:
	Text(std::string s) : TextView(s) {}

	void Draw() override { TextView::Show(); } 
};

// 객체   어답터 : 객체의 인터페이스 변경
//				   포함을 사용하게 됩니다.( 포함은 객체에 대한 변경, 추가 입니다.)
class Text2 : public Shape
{
	TextView* tv; // 포함(포인터또는 참조로), 포인터 이므로 외부 객체를 가리키게 됩니다
public:
	Text2(TextView* t) : tv(t) {}

	void Draw() override { tv->Show(); }
};
int main()
{
	vector<Shape*> v;
	
	TextView tv("Hello"); // TextView : 클래스,  tv : 객체
						// 이미, TextView 의 객체 tv 가 존재 합니다.
	// tv를 v에 넣을수 있을까요 ?
	//v.push_back(&tv); // v에 넣으려면 Shape 로 부터 파생되어야 하기 때문에 error
					  // 즉, 요구조건(인터페이스)가 맞지 않습니다.
					  // 220v 콘센트에 110v 용 플러그를 꼽는다고 생각해 보세요

	Text2 t(&tv); // 110v 플러그에 돼지코를 끼웠다고 가정해 보세요
				  // tv객체에 어답터 연결!!

	v.push_back(&t); // ok
	v[0]->Draw(); // t->Draw()인데.. 결국 tv->Show() 호출..
}







