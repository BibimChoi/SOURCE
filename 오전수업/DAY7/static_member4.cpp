// 아래 코드에서 에러 찾으세요
/*
class A
{
	int data;
public:
	void foo()
	{
		*data = 10; // error
	}
};
int main()
{
	A a;
}
*/
//---------------
template<typename T> class A
{
	T data;
public:
	void foo()
	{
		*data = 10; // error
	}
};
int main()
{
	A<int> a;

	a.foo(); // 이렇게 foo를 사용하면
			// 컴파일 에러가 나옵니다.
			// 그런데, 사용하지 않으면
			// foo 자체가 인스턴스화(템플릿 => C++코드로 생성) 되지 않으므로 에러가아닙니다
			// "지연된 인스턴스화"
}








