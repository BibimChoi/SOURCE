template<typename T> class Test
{
public:
	void foo(T&& arg) {}
};

int main()
{
	int n = 0;

	Test<int> t;

	// 다음 코드가 에러가 있을지 생각해 보세요
	t.foo(10);
	t.foo(n);
}