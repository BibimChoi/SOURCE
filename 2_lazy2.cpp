// �Ʒ� �ڵ�� ������ �ϸ� ������ ������� ?
template<typename T> void foo(T a)
{
	if (false)
		*a = 10;
}

int main()
{
	foo(10);
}