
class ClosureType
{
	int v1;
	int v2;
public:
	ClosureType(int v1, int v2) : v1(v1), v2(v2) {}

	inline int operator()(int a, int b) const
	{
		return a + b + v1 + v2;
	}
	// 결론 : 캡쳐한 람다 표현식에는 아래 함수를 만들수 없습니다.
	//     그래서, 함수 포인터로의 변환이 안됩니다.
	inline static int helper(int a, int b)
	{
		return a + b + v1 + v2; // static 멤버 함수에서는 멤버 데이타 접근 안됨!!!!
	}							// error..


	using F = int(*)(int, int);

	operator F()
	{
		return &ClosureType::helper;
	}
};

int main()
{
//	int(*f)(int, int) = ClosureType(v1, v2); 

	// 캡쳐한 람다표현식은 함수포인터로 변환될수 없습니다
	int v1 = 10, v2 = 10;
	int(*f)(int, int) = [v1, v2](int a, int b) { return a + b + v1 + v2; }; 
						// class xxxx{}; xxxx()
}








