#define USING_GUI
#include "cppmaster_gui.h"

/*
int foo(int hwnd,	// 이벤트가 발생한 윈도우의 번호(핸들
		int msg,	// 이벤트 종류..(마우스, 키보드등)
		int a, int b) // 이벤트의 종류에 따른 추가 정보(마우스, 키보드)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN" << hwnd << std::endl; break;
	}
	return 0;
}
int main()
{
	int h1 = ec_make_window(foo, "A");
	int h2 = ec_make_window(foo, "B");

	ec_process_message();
}
*/

// C++로 GUI 라이브러리를 설계해 봅시다.
// 아래 클래스가 라이브러리 내부 클래스 입니다.

class CWnd;
std::map<int, CWnd*> this_map; // 윈도우 핸들(int)을 키값으로 this 보관할
							   // 자료 구조.

class CWnd
{
public:
	void Create()
	{
		int handle = ec_make_window( msgproc, "A" );

		// 윈도우 번호를 키값으로 this 보관
		this_map[handle] = this;
	}
	static int msgproc(int hwnd, int msg, int a, int b)
	{
		CWnd* self = this_map[hwnd];

		// 이벤트에 따라 해당하는 가상함수 호출
		switch (msg)
		{
		case WM_LBUTTONDOWN: self->LButtonDown(); break; // this->LButtonDown()
		case WM_KEYDOWN:     self->KeyDown(); break;
		}
		return 0;
	}

	virtual void LButtonDown() {}
	virtual void KeyDown() {}
};


// 아래 클래스는 라이브러리 사용자 클래스 라고 생각해 봅시다
class MyWindow : public CWnd
{
public:
	void LButtonDown() { cout << "LBUTTON" << endl; }
};

int main()
{
	// 사용법
	MyWindow w;
	w.Create(); // 이순간 윈도우가 생성되고
				// 마우스를 누르면 가상함수 LButtonDown()이 호출되야합니다.

	ec_process_message();
}
