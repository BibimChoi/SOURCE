template<typename T> class Test
{
public:
	void foo(T&& arg) {}
};

int main()
{
	int n = 0;

	Test<int> t;

	// ���� �ڵ尡 ������ ������ ������ ������
	t.foo(10);
	t.foo(n);
}