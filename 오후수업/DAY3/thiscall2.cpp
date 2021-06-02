#include <functional> // std::invoke

// 핵심 1. 일반 함수 포인터에 멤버함수의 주소를 담을수 없습니다.(this추가되므로)
//      2. 일반 함수 포인터에 static 멤버함수의 주소는 담을수 있습니다.

//      3. 멤버 함수 포인터를 만들고 사용하는 방법 - main 함수 코드 참고

class Dialog
{
public:
	void Close(int n) {}
	static void Close2(int n) {}
};

void foo(int n) {}

int main()
{
	void(*f1)(int) = &foo;				// ok
//	void(*f2)(int) = &Dialog::Close;	// error. this가 추가되는 함수!
	void(*f3)(int) = &Dialog::Close2;   // ok.. this가 추가되지 않은 함수


	// 그럼 아래 코드는 되나요 ?
//	void(*f2)(Dialog*, int) = &Dialog::Close; // 안됩니다. 객체주소는 실제인자와는 다르게
											// 레지스터(ecx)로 보내게 되므로!!

	// 1. 멤버 함수의 주소를 담는 포인터 만드는 법
	void(Dialog::*f2)(int) = &Dialog::Close; // ok

	// 2. 멤버 함수 포인터로 함수 호출하기
	// f2(10); // error. 객체(this)가 없습니다

	Dialog dlg;
//	dlg.f2(10); // error. dlg 안에는 f2라는 함수를 찾는데.. 없으므로 에러

//	dlg.*f2(10);// .* : pointer to member 라는 연산자(C 에는 없고, C++만제공)
				// 이 코드는 연산자 우선순위 문제로 error

	(dlg.*f2)(10); // ok.. 이 코드가 멤버함수 포인터로 멤버함수를 호출하는 코드
					// 입니다.
	
	// 함수 포인터 사용방법을 동일시 할수 없을까 ??
	f1(10);        // 일반 함수 포인터
	(dlg.*f2)(10); // 멤버 함수 포인터

//	f2(&dlg, 10); // 이 표기법은 어떤까요 ?
				  // C++ 창시자가 제안한 "uniform call syntax" 라는 문법
				  // C++17부터 제안했으나 채택 안됨.

	// 대신, C++17 에서는 std::invoke()가 있습니다. 편리합니다.
	std::invoke(f1, 10);        // f1(10)의 의미
	std::invoke(f2, &dlg, 10);  // (dlg.*f2)(10)의 의미
								// std::mem_fn (C++11) 도 있지만 
								// invoke가 많이 사용됩니다.
}












