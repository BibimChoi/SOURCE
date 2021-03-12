// 2_람다표현식1 - 127 page

int add(int a, int b) { return a + b; }

void foo(  int(*f)(int, int) ) // 인자로 함수주소(함수이름)를 보내야 한다.
{
}

int main()
{
	foo(add); // ok  
	
	// 람다 표현식 : 함수 이름(주소)가 필요한 곳에 함수 구현을 직접 넣는 문법
	// [] : 람다표현식이 시작됨을 알리는 기호
	//      lambda introducer
	foo( [](int a, int b) { return a + b; } );

}     