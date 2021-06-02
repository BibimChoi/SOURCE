#define USING_GUI
#include "cppmaster_gui.h"
#include <map>
#include <vector>

class CWnd;
map<int, CWnd*> this_map;

class CWnd
{
	int mHandle;

	CWnd* parent = nullptr;		  // 부모 윈도우는 한명뿐 입니다.
	std::vector<CWnd*> child_vec; // 자식윈도우는 여러개
public:
	void AddChild(CWnd* p)
	{
		child_vec.push_back(p);
		p->parent = this;

		// 실제 윈도우 관련 C 함수로 자식 윈도우로 붙이는 코드
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
	// 아래 함수가 "책임의 전가(Chain Of Responsibility)" 패턴의 핵심 구현입니다.
	void FireLButtonDown()
	{
		// 1. event를 처리할 권한은 일단 자신에게 있다.
		if (this->LButtonDown() == true)
			return;		// 자신이 처리한 경우는 event 처리 종료

		// 2. 자신이 event를 처리하지 않았거나 false 를 반환했으면
		//    부모 윈도우에게 전달한다.
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

	// w2를 w에 자식윈도우로 붙인다.
	w.AddChild(&w2);

	ec_process_message();
}



