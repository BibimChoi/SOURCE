

// cafe.naver.com/cppmaster 에서 "DAY5.zip" 받으세요


       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

// 1. 인라인 치환은 컴파일 시간에 이루어 진다.
// 2. 아무리 인라인 함수라도 함수 포인터에 담아서 사용하면 치환될수 없다.

int main()
{
	int n1 = Add1(1, 2); // 함수 호출
	int n2 = Add2(1, 2); // 함수 기계어 코드 치환

	int(*f)(int, int) = &Add2;

//	if (사용자 입력 == 1) f = &Add1;

	f(1, 2); // 호출 ? 치환
}

