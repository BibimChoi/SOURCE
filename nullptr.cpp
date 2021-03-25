// nullptr.cpp

void foo(int* p) {}
void goo(char* p) {}

// nullptr 의 원리
// 1. boost 라이브러리 팀에서 아래 처럼 만들어서 사용
struct nullptr_t
{
	// 변환 연산자 : 객체가 다른 타입으로 암시적 변환 될때 호출.
	//				 특징은 리턴 타입을 표기하지 않습니다.
	operator int*() const { return 0; }
};
nullptr_t xnullptr;

int main()
{
	foo(xnullptr);  // xnullptr => int* 로의 암시적 변환 필요
					// xnullptr.operator int*() 라는 변환 연산자 함수 호출
//	goo(xnullptr);
}
