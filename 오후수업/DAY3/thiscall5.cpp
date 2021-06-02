#define USING_GUI
#include "cppmaster_gui.h"


/*
int foo(int hwnd,	// event가 발생한 윈도우 번호
		int msg,	// event(메세지 번호)
		int a, int b)// event 추가 정보(마우스 좌표등)
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



// 아래 클래스가 라이브러리 내부 클래스 입니다.

class CWnd;

std::map<int, CWnd*> this_map;

class CWnd
{
public:
	void Create()
	{
		int handle = ec_make_window(foo, "A");

		this_map[handle] = this;
	}
	static int foo(int hwnd, int msg, int a, int b)
	{
		CWnd* pThis = this_map[hwnd];

		// pThis 만 있으면 모든 멤버 접근 가능
		switch (msg)
		{
		case WM_LBUTTONDOWN: pThis->LButtonDown(); break; // 약속된 가상함수 호출
		case WM_KEYDOWN:     pThis->KeyDown();     break; // this->KeyDown()이 되야 한다.
		}
		return 0;
	}

	virtual void LButtonDown() {}
	virtual void KeyDown() {}
};

// 아래 코드는 라이브러리 사용자 코드 입니다.
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
