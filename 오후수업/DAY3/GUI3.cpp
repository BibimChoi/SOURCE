#define USING_GUI
#include "cppmaster_gui.h"
#include <map>
#include <vector>
#include <functional>
// MessageMap

class CWnd;
map<int, CWnd*> this_map;

struct AFX_MSG
{
	int messageno;			// 메세지 번호
	void(CWnd::*handler)();	// 멤버 함수 주소를 담을 변수
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

	// 아래 가상 함수에서 event 처리 정보를 담은 배열을
	// 반환해야 합니다.
	virtual AFX_MSG* GetMessageMap()
	{
		return nullptr;
	}



	static int foo(int hwnd, int msg, int a, int b)
	{
		CWnd* const pThis = this_map[hwnd];

		if (pThis == nullptr) return 0;

		// event 처리 정보를 담을 배열을 얻어온다.
		AFX_MSG* arr = pThis->GetMessageMap();

		if (arr == nullptr) return 0;

		while (arr->messageno != 0)
		{
			if (arr->messageno == msg)
			{
				std::invoke(arr->handler, pThis); // invoke(멤버함수주소, 객체주소)
						// (pThis->*(arr->handler))()   
			}
			++arr;
		}



		return 0;
	}

};


class MyWindow : public CWnd
{
public:
	void LButtonDown() { cout << "LBUTTON" << endl; }
	void KeyDown()     { cout << "KEYDOWN" << endl; }

	// 라이브러리 사용자는 GetMessageMap() 재정의 해서
	// event table 주소 반환하면 됩니다.
	AFX_MSG* GetMessageMap() override
	{
		typedef void(CWnd::*HANDLER)(); // 멤버 함수 포인터 타입

		static AFX_MSG arr[] = {
			{ WM_LBUTTONDOWN, static_cast<HANDLER>(&MyWindow::LButtonDown)},
			{ WM_KEYDOWN,     static_cast<HANDLER>(&MyWindow::KeyDown)},
			{0, 0}
		};

		return arr;
	}
};




int main()
{
	MyWindow w;
	w.Create();

	ec_process_message();
}



