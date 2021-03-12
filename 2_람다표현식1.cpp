// 2_람다표현식1 - 127 page

int add(int a, int b) { return a + b; }

void foo(  int(*f)(int, int) )
{
}

int main()
{
	foo(add); // ok 

	// 람다 표현식 : 함수이름(또는 주소)가 필요한 자리에 
	//				함수 구현 자체를 표기하는 문법
	// [] :람다가 시작됨을 알리는 기호
	//		"lambda introducer" 라고 합니다.

	foo( [](int a, int b) { return a + b; } );
}