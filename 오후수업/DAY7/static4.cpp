// static4.cpp

// 아래 코드에서 에러가 나오는 부분을 찾으세요
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
template<typename T>
class A
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
//	a.foo();  // 이렇게 사용하는 코드가 있어야 
			  // foo 함수가 인스턴스화(템플릿 => 실제 C++클래스코드)됩니다.
			  // 따라서, 사용하는 코드가 없으면 "*data = 10" 은 에러가 아닙니다.
}

// 템플릿의 인스턴스화 결과를 알수 없나요 ?? => 보통 어셈으로 확인하게 됩니다.
// 또는 cppinsight.so 사이트 가 좋긴 합니다.

// 멤버 함수, static 멤버 데이타 : 사용되지 않으면 인스턴스화 안됨.
// non-static 멤버 데이타 : 객체를 생성하면 무조건 메모리 놓여야 하므로 
//						사용된 것으로 간주

//A<int> a; // a.data 를 사용한 적이 없지만, 멤버 데이타인 data는인스턴스화 됩니다.





