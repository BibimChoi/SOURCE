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
	DECLARE_MESSAGE_MAP()

	void LButtonDown() { cout << "LBUTTON" << endl; }
	void KeyDown()     { cout << "KEYDOWN" << endl; }
};
BEGIN_MESSAGE_MAP( MyWindow )
	ADD_MESSAGE( WM_LBUTTONDOWN, &MyWindow::LButtonDown )
END_MESSAGE_MAP()





int main()
{
	MyWindow w;
	w.Create();

	ec_process_message();
}



