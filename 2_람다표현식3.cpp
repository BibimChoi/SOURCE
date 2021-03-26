
class ClosureType
{
public:
	inline int operator()(int a, int b) const
	{
		return a + b;
	}

	inline static int helper(int a, int b)
	{
		return a + b;
	}

	using F = int(*)(int, int);

	operator F()
	{
		return &ClosureType::helper;

//		return &ClosureType::operator(); // error. 멤버 함수 이므로 this가 추가됩니다.
								// 그리고, operator() 는 static 멤버로 만들수 없습니다.
	}
};

int main()
{
	int(*f)(int, int) = ClosureType(); // 객체.opertor 함수포인터()

//	int(*f)(int, int) = [](int a, int b) { return a + b; }; 
						// class xxxx{}; xxxx()
}








