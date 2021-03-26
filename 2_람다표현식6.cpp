// generic lambda�� ����
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

	// C++14���� �߰��� generic lambda
	auto f = [](auto a, auto b) { return a + b; };

	f(1, 2);
	f(3.4, 2.1);
	f(3.4, 2);


	// swap �� ���ٷ� ����� ���ô�.
	//auto f2 = [](auto& a, auto& b) { auto tmp = a; a = b; b = tmp; };
	//auto f2 = [](auto& a, decltype(a)& b) { auto tmp = a; a = b; b = tmp; };
	//           int& a, int& b

	// C++20 �� template ����
	auto f2 = []<typename T>(T& a, T& b) { auto tmp = a; a = b; b = tmp; };


	int n = 10;
	double d = 3.4;
	f2(n, d); // ??? �Ǵ°� ������� ? �ȵǴ°� ������� ?
}








