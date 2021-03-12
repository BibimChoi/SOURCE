// 상수 멤버 함수는 문법은 선택이 아닌 필수 입니다.

// 객체의 상태를 변경하지 않은 모든 멤버 함수(getter)는

// 반드시 상수 멤버함수로 해야 합니다.

class Rect
{
	int x, y, w, h;
public:
	int getArea() const { return w * h; }
};

//void foo(Rect r) // call by value 는 복사본에 따른 오버헤드가 있다.
void foo(const Rect& r)
{
	int n = r.getArea(); // r은 상수객체임..
}

int main()
{
	Rect r; // 초기화 했다고 가정..  => 상수객체 아님.
	int n = r.getArea(); // ok.. 
	foo(r);
}