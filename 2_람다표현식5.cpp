int main()
{
	int v1 = 0, v2 = 0;
	auto f = [v1, v2](int a, int b) { return a + b; };

	decltype(f) f1;

	decltype(f) f2 = f;
}