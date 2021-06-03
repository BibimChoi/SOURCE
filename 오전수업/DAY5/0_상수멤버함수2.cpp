// 0_상수멤버함수2
// 핵심 : 상수 멤버 함수문법은 선택이 아닙니다. 필수 문법입니다.
//        멤버 값을 변경하지 않은 모든 멤버함수(getter)는 반드시 상수 멤버 함수가
//		  되어야 합니다.
class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}

	int getArea() const { return w * h; }
};
//void foo(Rect r)		// call by value : 복사본 의 오버헤드가 있다.
void foo(const Rect& r) // call by value 보다 const 참조가 좋다.
{
	int n = r.getArea(); // error. getArea()가 상수 멤버 함수가 아니라면
}
int main()
{
	Rect r(1, 1, 10, 10);  // 상수 객체 아님.
	int n = r.getArea();   // ok.
	foo(r);					//
}
