
// 아주 중요 합니다. 
// 함수 인자로
// int&  : 정수형 lvalue 만 받을수 있다.
// int&& : 정수형 rvalue 만 받을수 있다.

// T&    :

void f1(int&  r) {}
void f2(int&& r) {}

template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 10;

	// 1. 사용자가 타입을 전달하는 경우
	f3<int>(? );    // T=			T&&=			f3(? )
	f3<int&>(? );   // T=			T&&=			f3(? )
	f3<int&&>(? );  // T=			T&&=			f3(? )
}











template<typename T> void f4(T&& a)
{
}






