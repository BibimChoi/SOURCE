inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less { inline bool operator()(int a, int b) { return a < b; } };
struct Greater { inline bool operator()(int a, int b) { return a > b; } };

template<typename T> void foo(T f)
{
	bool b = f(1, 2);
}
int main()
{
	Less f1;
	Greater f2;

	foo(cmp1);
	foo(cmp2);
	foo(f1);
	foo(f2);
}
// 1. 위 코드 실행시 foo 함수의 갯수는 ?
// 2. 각 foo에서 f(1,2) 의 인라인 치환 여부 ?
// 3. foo 를 제외한 나머지 함수의 갯수는 ?