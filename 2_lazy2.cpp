// 아래 코드는 컴파일 하면 에러가 있을까요 ?
template<typename T> void foo(T a)
{
	if (false)
		*a = 10;
}

int main()
{
	foo(10);
}