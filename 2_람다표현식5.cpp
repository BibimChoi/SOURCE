int main()
{
	int v1 = 0, v2 = 0;

	auto f = [v1, v2](int a, int b) { return a + b; };


	// 아래 2줄을 생각해 봅시다.
	// 람다표현식을 보고 컴파일러가 만드는 클래스는
	// 1. 디폴트 생성자는 없다.
	// 2. 복사 생성자는 있다.
	decltype(f) f1;  // error. 람다표현식은 디폴트 생성자가 없습니다.
					 // 멤버 데이타인  v1, v2가 초기화 되지 않기 때문

	decltype(f) f2 = f; //  ok..

	// 캡쳐를 안하면
	auto f3 = [](int a, int b) {return a + b; };

	decltype(f3) f4; // ??
}