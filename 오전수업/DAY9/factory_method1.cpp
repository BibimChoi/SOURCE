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
// Style 옵션에 관계없이 항상 윈도우 모양으로 나타나는 Dialog..

class WinDialog
{
public:
	void Init()
	{
		WinButton* btn = new WinButton;
		WinEdit*   edit = new WinEdit;

//		btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
};
class OSXDialog
{
public:
	void Init()
	{
		OSXButton* btn = new OSXButton;
		OSXEdit*   edit = new OSXEdit;

		//		btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
};

int main(int argc, char** argv)
{

}









