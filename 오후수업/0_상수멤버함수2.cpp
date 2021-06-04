// 0_상수멤버함수2

// 상수 멤버 함수는 선택이 아닌 필수 문법 입니다.
// 멤버 데이타의 값을 변경하지 않은 모든 멤버 함수(getter) 는 반드시 
// 상수 멤버 함수로 해야 합니다.!! 

// getxxx 으로 시작하는 함수는 반드시 상수 멤버 함수 로 하세요

class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}

	int getArea() const  { return w * h; }
};


//void foo(Rect r)      // call by value : 복사본에 의한 오버헤드가 있다.
void foo(const Rect& r) // call by value 보다는 const 참조가 좋다.
{
	int n = r.getArea(); // ?
}

int main()
{
	Rect r(1, 1, 10, 10);
	int n = r.getArea(); // ok.. 
	foo(r);
}


