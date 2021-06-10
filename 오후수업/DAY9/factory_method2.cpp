// 3_추상팩토리 - 147
#include <iostream>

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};

//--------------------------------
// 변하지 않으면 "기반 클래스"
// 변하는 것은 "가상함수로 해서 파생 클래스가 재정의"
class BaseDialog
{
public:
	void init()
	{
		IButton* btn = CreateButton();
		IEdit*   edit = CreateEdit();

		//		btn->Move(); 
		//		edit->Move();

		btn->Draw();
		edit->Draw();
	}
	// Factory Method 패턴
	// "객체를 만들기 위한 인터페이스를 정의하고 사용하지만"
	// "어떤 객체를 만들지는 파생 클래스가 결정한다."
	// "객체의 생성의 파생 클래스로 미루는 패턴"
	// "template method"와 동일한 모양인데..
	// 가상함수가 하는일이 객체의 종류를 결정한다.
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
};

// 스타일 옵션에 상관없이 항상 Windows 모양으로 나타나는 Dialog
class WinDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new WinButton; }
	IEdit*   CreateEdit()   override { return new WinEdit; }
};

class OSXDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new OSXButton; }
	IEdit*   CreateEdit()   override { return new OSXEdit; }
};


int main(int argc, char** argv)
{

}








