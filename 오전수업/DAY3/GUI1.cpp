#define USING_GUI
#include "cppmaster_gui.h"
#include <map>
#include <vector>

class CWnd;
map<int, CWnd*> this_map;

class CWnd
{
	int mHandle;

	CWnd* parent;		// 부모 윈도우는 한명뿐 입니다.
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
		case WM_LBUTTONDOWN: pThis->LButtonDown(); break;
		case WM_KEYDOWN:     pThis->KeyDown(); break;
		}
		return 0;
	}
	virtual void LButtonDown() {}
	virtual void KeyDown() {}
};


class MyWindow : public CWnd
{
public:
	void LButtonDown() { cout << "MyWindow LBUTTON" << endl; }
};
class ImageView : public CWnd
{
public:
	void LButtonDown() { cout << "ImageView LBUTTON" << endl; }
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



