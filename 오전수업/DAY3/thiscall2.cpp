#include <functional>

// 1. 일반 함수 포인터에 멤버 함수의 주소를 담을수 없습니다(this 때문에!!)
// 2. 일반 함수 포인터에 static 멤버 함수의 주소를 담을수 있습니다.
// 3. 멤버 함수 포인터를 만들고 사용하는 방법 - main 함수 참고!
class Dialog
{
public:
	void Close(int a) {}
	static void Close2(int a) {}
};

void foo(int a) { }

int main()
{
	void(*f1)(int) = &foo;				// ok
//	void(*f2)(int) = &Dialog::Close;	// error. this가 추가되는 함수입니다
	void(*f3)(int) = &Dialog::Close2;   // ok

	// 멤버 함수의 주소를 담는 멤버 함수 포인터를 만드는 방법.
	void(Dialog::*f2)(int) = &Dialog::Close;

	// 멤버 함수 포인터로 함수 호출하기
	// f2(10);  // error. 객체(this)가 없습니다.!

	Dialog dlg;
	// dlg.f2(10); // error. dlg 에서 f2라는 함수를 찾게됩니다.없으므로 error

	//dlg.*f2(10);  // .* : pointer to member 라는 이름을 가지는 연산자(C++에서 추가됨)
					// ERROR. 연산자 우선 순위 문제로!!!

	(dlg.*f2)(10); // ok.. 이 표기법이 멤버 함수 포인터를 사용해서 
					// 멤버 함수를 호출하는 표기법입니다.
					// 

	// 함수 포인터 사용법을 동일화 할수 없을까 ?
	f1(10);			// 일반 함수 포인터로 함수 호출
	(dlg.*f2)(10);	// 멤버 함수 포인터로 함수 호출

//	f2(&dlg, 10);	// 이렇게 할수 있으면 좋지 않을까 ?
					// C++창시자가 이 코드를 되도록하자고 제안
					// (uniform call syntax 라는 이름의 문법 제안)
					// 그러나, 채택 안됨

	// 대신 C++17 에서 invoke() 를 표준으로 제공
	std::invoke(f1, 10);		// 일반 함수 호출
	std::invoke(f2, &dlg, 10);	// 멤버 함수 호출
}






