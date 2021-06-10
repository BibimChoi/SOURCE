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
//-------------------------

// Abstract Factory(추상 팩토리)패턴

// 제품의 군을 생성하기 위한 인터페이스를 정의 한다.
// 어떤 제품의 군을 만들지는 파생클래스가 결정한다.
// 즉, 공장도 인터페이스를 만들고, 교체 가능하게 하자는 패턴
struct IFactory
{
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
	virtual ~IFactory() {}
};
// 각 OS 별 컨트롤을 만드는 공장을 도입합니다.
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
	IEdit*   CreateEdit()   { return new OSXEdit; }
};
int main(int argc, char** argv)
{
	IFactory* factory;

	if (strcmp(argv[1], "-style:OSX") == 0)
		factory = new OSXFactory;
	else
		factory = new WinFactory;

	// 이제 컨트롤이 필요하면 공장으로 부터 생성합니다
	IButton* btn1 = factory->CreateButton();
	IButton* btn2 = factory->CreateButton();

}








