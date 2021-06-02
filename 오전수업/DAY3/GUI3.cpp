#define USING_GUI
#include "cppmaster_gui.h"
#include <map>
#include <vector>

// MessageMap

class CWnd;
map<int, CWnd*> this_map;


struct AFX_MSG
{
	int messageno;				// 메세지 번호
	void (CWnd::*handler)();	// 메세지를 처리할 함수
};



class CWnd
{
	int mHandle;
public:
	void Create()
	{
		mHandle = ec_make_window(foo, "A");
		this_map[mHandle] = this;
	}

	// 아래 가상 함수에서 메세지 처리 정보를 담은 배열을 반환해야합니다
	virtual AFX_MSG* GetMessageMap()
	{
		return nullptr;
	}

	static int foo(int hwnd, int msg, int a, int b)
	{
		CWnd* const pThis = this_map[hwnd];

		if (pThis == nullptr) return 0;

		// 메세지 처리 정보를 담은 배열을 얻어 옵니다.
		AFX_MSG* arr = pThis->GetMessageMap();

		if (pThis == nullptr) return 0; // 처리할 메세지 없는 경우

		while (arr->messageno)
		{
			if (arr->messageno == msg)
			{
				void(CWnd::*handler)() = arr->handler;
				(pThis->*handler)(); // 멤버 함수 호출 - thiscall2 번 참고
			}
			++arr;
		}
		return 0;
	}
};




class MyWindow : public CWnd
{
public:
	// 라이브러리 사용자는 아래 가상함수를 재정의해서
	// 메세지 처리 정보를 담은 배열을 반환해야 합니다.
	AFX_MSG* GetMessageMap() override
	{
		typedef void(CWnd::*HANDLER)(); // 멤버 함수 포인터 타입

		static AFX_MSG arr[] = {
			{ WM_LBUTTONDOWN, static_cast<HANDLER>(&MyWindow::LButtonDown)},
			{ WM_KEYDOWN,     static_cast<HANDLER>(&MyWindow::KeyDown)},
			{ 0, 0}
		};
		return arr;
	}

	void LButtonDown() { cout << "LBUTTON" << endl; }
	void KeyDown()     { cout << "KEYDOWN" << endl; }
};




int main()
{
	MyWindow w;
	w.Create();

	ec_process_message();
}



