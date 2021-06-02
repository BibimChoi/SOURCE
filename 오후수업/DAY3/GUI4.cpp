#define USING_GUI
#include "cppmaster_gui.h"
#include <map>
#include <vector>
#include <functional>


class CWnd;
map<int, CWnd*> this_map;

struct AFX_MSG
{
	int messageno;			
	void(CWnd::*handler)();	
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

		if (arr == nullptr) return 0;

		while (arr->messageno != 0)
		{
			if (arr->messageno == msg)
			{
				std::invoke(arr->handler, pThis); 
			}
			++arr;
		}



		return 0;
	}

};

#define DECLARE_MESSAGE_MAP()		AFX_MSG* GetMessageMap() override;


#define BEGIN_MESSAGE_MAP(classname)		\
	AFX_MSG* classname::GetMessageMap() 	\
	{										\
		typedef void(CWnd::*HANDLER)();		\
		static AFX_MSG arr[] = {


#define ADD_MESSAGE(msgno, function)	\
	{ msgno, static_cast<HANDLER>(function)},

#define END_MESSAGE_MAP()		\
				{0, 0}			\
			};					\
			return arr;			\
			}

// 이제 위 라이브러리의 최종 사용자 코드는 아래와 같습니다. 
class MyWindow : public CWnd
{
public:
	void LButtonDown() { cout << "LBUTTON" << endl; }
	void KeyDown() { cout << "KEYDOWN" << endl; }

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(MyWindow)
	ADD_MESSAGE(WM_LBUTTONDOWN, &MyWindow::LButtonDown)
END_MESSAGE_MAP()


// WM_KEYDOWN 과 KeyDown연결해 보세요

// 구글에서 "wxWidget event table" 검색해 보세요, 1번째 링크

// C++ 의 대표적 GUI 라이브러리 - 이벤트 처리시 가상함수 방식의 오버헤드
//								자신들만의 이벤트 처리 기술 제공
// QT       : 대부분의 모든 OS지원,  signal / slot
// wxWidget : 대부분의 모든 OS지원,  위 코드와 유사한 기술
// MFC      : windows os 전용       위 코드와 유사한 기술

// 단점, 위 3개가 너무 오래된 라이브러리(1990년대 탄생)
// 최신 C++ GUI 라이브러리가 없다!!!( "nana" 라는것이 있지만....)

// C++23 에서 2D 그래픽라이브러리가 표준에 들어올 예정


int main()
{
	MyWindow w;
	w.Create();

	ec_process_message();
}



