// generic lambda의 원리
class ClosureType
{
public:
	template<typename T, typename U>
	inline auto operator()(T a, U b) const
	{
		return a + b;
	}
};

int main()
{
//	auto f = [](int a, int b) { return a + b; };

	// C++14에서 추가된 generic lambda
	auto f = [](auto a, auto b) { return a + b; };

	f(1, 2);
	f(3.4, 2.1);
	f(3.4, 2);
}