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


	// swap 을 람다로 만들어 봅시다.
	//auto f2 = [](auto& a, auto& b) { auto tmp = a; a = b; b = tmp; };
	//auto f2 = [](auto& a, decltype(a)& b) { auto tmp = a; a = b; b = tmp; };
	//           int& a, int& b

	// C++20 의 template 람다
	auto f2 = []<typename T>(T& a, T& b) { auto tmp = a; a = b; b = tmp; };


	int n = 10;
	double d = 3.4;
	f2(n, d); // ??? 되는게 좋을까요 ? 안되는게 좋을까요 ?
}








