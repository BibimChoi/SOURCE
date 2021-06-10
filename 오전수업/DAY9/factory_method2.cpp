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
	void Draw() { cout << "Draw OSXButton" << endl; }
};
//-------------------------------------------

// 핵심
// 모든 클래스의 공통의 특징 : 기반 클래스로 제공
// 각 클래스 별로 변해야 하는것 : 가상함수로 분리

class BaseDialog
{
public:
	void Init()
	{
		IButton* btn = CreateButton();
		IEdit*   edit = CreateEdit();

		//		btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
	// "Factory Method 패턴"
	// 객체를 만들기 위한 인터페이스를 제공하고 사용하지만
	// 어떤 객체를 만들지는 파생 클래스가 결정한다
	// 객체의 생성을 파생 클래스에 미루는 패턴!!
	//  "템플릿 메소드"와 동일한 구조를 가지는 패턴
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
};

// Style 옵션에 관계없이 항상 윈도우 모양으로 나타나는 Dialog..
class WinDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new WinButton; }
	IEdit*   CreateEdit()   override { return new WinEdit; }
};
class OSXDialog
{
public:
	IButton* CreateButton() override { return new OSXButton; }
	IEdit*   CreateEdit()   override { return new OSXEdit; }
};

int main(int argc, char** argv)
{
}
