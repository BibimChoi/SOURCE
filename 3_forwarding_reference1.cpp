
// 아주 중요 합니다. 
// 함수 인자로
// int&  : 정수형 lvalue 만 받을수 있다.
// int&& : 정수형 rvalue 만 받을수 있다.
// T&    : 임의 타입의 lvalue 만 받을수 있다.
// T&&   :

void f1(int&  r) {}
void f2(int&& r) {}

template<typename T> void f3(T& a)
{
}
int main()
{
	int n = 10;

	// 1. 사용자가 타입을 전달하는 경우
	f3<int>(n);    // T=int		T&=int&			f3(int& a )
	f3<int&>(n);   // T=int&	T&=int& &		f3(int& a )
	f3<int&&>(n);  // T=int&&	T&=int&& &		f3(int& a )

	// 2. 사용자가 타입을 전달하지 않으면 컴파일러가 인자를 보고
	//	  함수를 생성하기 위해서 T를 결정합니다.
	f3(10); // T를 int, int&, int&& 중 어떠한 것으로 결정해도 받을수 없다.
			// 컴파일 에러.
	f3(n);  // T=int 로 결정!
}











template<typename T> void f4(T&& a)
{
}
int main()
{
	int n = 10;

	// 1. 인자를 명시적으로 전달하는 경우
	f4<int>(? );   // T=       T&&=        f4(? a)
	f4<int&>(? );  // T=       T&&=        f4(? a)
	f4<int&>(? );  // T=       T&&=        f4(? a)
}




