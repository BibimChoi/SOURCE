#define USING_GUI
#include "cppmaster_gui.h"
#include <map>
#include <vector>

class CWnd;
map<int, CWnd*> this_map;


struct AFX_MSG
{
	int messageno;				
	void (CWnd::*handler)();	
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

	virtual AFX_MSG* GetMessageMap()
	{
		return nullptr;
	}

	static int foo(int hwnd, int msg, int a, int b)
	{
		CWnd* const pThis = this_map[hwnd];

		if (pThis == nullptr) return 0;

		AFX_MSG* arr = pThis->GetMessageMap();

		if (pThis == nullptr) return 0; 

		while (arr->messageno)
		{
			if (arr->messageno == msg)
			{
				void(CWnd::*handler)() = arr->handler;
				(pThis->*handler)();
			}
			++arr;
		}
		return 0;
	}
};



// 메세지 처리를 위한 코드를 매크로화 합니다.
#define DECLARE_MESSAGE_MAP()		AFX_MSG* GetMessageMap() override;

#define BEGIN_MESSAGE_MAP(classname)	\
	AFX_MSG* classname::GetMessageMap() \
	{                                   \
		typedef void(CWnd::*HANDLER)(); \
		static AFX_MSG arr[] = {

#define ADD_MESSAGE(messageno, function)	\
			{ messageno, static_cast<HANDLER>(function)},

#define END_MESSAGE_MAP()			\
					{ 0, 0}			\
				};					\
				return arr;			\
			}


class MyWindow : public CWnd
{
public:
	void LButtonDown() { cout << "LBUTTON" << endl; }
	void KeyDown()     { cout << "KEYDOWN" << endl; }

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP( MyWindow )
	ADD_MESSAGE( WM_LBUTTONDOWN, &MyWindow::LButtonDown )
	ADD_MESSAGE( WM_KEYDOWN,     &MyWindow::KeyDown)
END_MESSAGE_MAP()

// GUI 이벤트는 1000개 이상입니다. 
// 이벤트를 가상함수 기반으로 처리하면 "가상함수 테이블"의 오버헤드가 있습니다.
// 그래서 위처럼 하는 경우가 많이 있었습니다 - MFC, wxWidget 이 대표적으로 이기술 사용
// 요즘에는 "메모리가 충분해서 가상함수도 많이 사용"

// 구글에서 "wxWidget event table" 검색해 보세요  - 1번째 링크

// C++ 기반 GUI 라이브러리
// MFC, QT, wxWidget 등.. 문제점.. 너무오래 되었다.(1990년대 나온것들 )

// 최신 라이브러리로 "nana" 라는 GUI 도구가 있습니다.

int main()
{
	MyWindow w;
	w.Create();

	ec_process_message();
}



