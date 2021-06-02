// GUI5.cpp  - thiscall5.cpp 복사해 오세요.. 주석 제거하세요

#define USING_GUI
#include "cppmaster_gui.h"

class BaseWindow;
std::map<int, BaseWindow*> this_map;

class BaseWindow 
{
};

template<typename T> class CWnd : public BaseWindow
{
public:
	void Create()
	{
		int handle = ec_make_window(msgproc, "A");

		this_map[handle] = this;
	}
	static int msgproc(int hwnd, int msg, int a, int b)
	{
		//CWnd* self = this_map[hwnd];

		// 보관된 this를 꺼낼때 파생 클래스 타입의 포인터를 캐스팅해서 꺼냅니다.
		T* self = static_cast<T*>(this_map[hwnd]);

		switch (msg)
		{
		case WM_LBUTTONDOWN: self->LButtonDown(); break; // this->LButtonDown()
		case WM_KEYDOWN:     self->KeyDown(); break;
		}
		return 0;
	}

	// 핵심 : 이벤트를 처리하는 아래2개 함수는 "가상이 아닙니다."	
	void LButtonDown() {}
	void KeyDown() {}
};


class MyWindow : public CWnd< MyWindow >
{
public:
	void LButtonDown() { cout << "LBUTTON" << endl; }
	void KeyDown()     { std::cout << "KEYDOWN" << std::endl; }
};

int main()
{
	MyWindow w;
	w.Create(); 				

	ec_process_message();
}
