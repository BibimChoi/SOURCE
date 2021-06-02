#define USING_GUI
#include "cppmaster_gui.h"
#include <map>
#include <vector>

class CWnd;
map<int, CWnd*> this_map;

class CWnd
{
	int mHandle;

	CWnd* parent = nullptr; // 부모윈도우는 한개 입니다.
	std::vector<CWnd*> child_vec; // 자식 윈도우는 여러개 일수 있습니다.
public:
	void AddChild(CWnd* p)
	{
		child_vec.push_back(p);

		p->parent = this;

		// 실제 C 함수로 자식윈도우 부착
		ec_add_child(this->mHandle, p->mHandle);
	}






	void Create()
	{
		mHandle = ec_make_window(foo, "A");
		this_map[mHandle] = this;
	}

	static int foo(int hwnd, int msg, int a, int b)
	{
		CWnd* const pThis = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN: pThis->FireLButtonDown(); break;
		case WM_KEYDOWN:     pThis->KeyDown(); break;
		}
		return 0;
	}

	// 아래 함수가 책임의전가(chain of responsibility) 패턴의 핵심 입니다
	void FireLButtonDown()
	{
		// 1. event 처리의 우선권은 나에게 있다
		if (this->LButtonDown() == true)
			return;

		// 2. event 처리를 하지 않거나, false를 반환한 경우 부모 윈도우에 전달
		if (parent != nullptr)
			parent->FireLButtonDown();
	}


	virtual bool LButtonDown() { return false; }
	virtual void KeyDown() {}
};


class MyWindow : public CWnd
{
public:
	bool LButtonDown() 
	{ 
		cout << "MyWindow LBUTTON" << endl; 
		return true;
	}
};
class ImageView : public CWnd
{
public:
	bool LButtonDown() 
	{ 
		cout << "ImageView LBUTTON" << endl; 
		return true;
	}
};

int main()
{
	MyWindow w;
	w.Create();

	ImageView w2;
	w2.Create();

	w.AddChild(&w2);

	ec_process_message();
}



