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
//-------------------
// 추상 팩토리 패턴(Abstract Factory)
// 제품의 군을 만들기 위한 인터페이스를 정의 한다.
// 어떤 제품을 만들지는 파생 클래스에서 결정한다.
// 즉, 공장도 인터페이스를 만들고 교체 가능하게 설계 하자는 패턴.
struct IFactory
{
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
	virtual ~IFactory() {}
};

// 각 운영체제 별로 컨트롤을 만드는 공장을 제공한다.
class WinFactory : public IFactory
{
public:
	IButton* CreateButton() { return new WinButton; }
	IEdit*   CreateEdit()   { return new WinEdit; }
};
class OSXFactory : public IFactory
{
public:
	IButton* CreateButton() { return new OSXButton; }
	IEdit*   CreateEdit() { return new OSXEdit; }
};
int main(int argc, char** argv)
{
	IFactory* factory;

	if (strcmp(argv[0], "-style:OSX") == 0)
		factory = new OSXFactory;
	else
		factory = new WinFactory;

	// 이제 모든 컨트롤은 공장을 통해서 만들면 됩니다.
	IButton* btn1 = factory.CreateButton();
	IButton* btn1 = factory.CreateButton();
}









