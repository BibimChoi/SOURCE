// 아래 코드에서 에러 찾으세요
/*
class A
{
	int data;
public:
	void foo()
	{
		*data = 10; // error
	}
};
int main()
{
	A a;
}
*/
//---------------
template<typename T> class A
{
	T data;
public:
	void foo()
	{
		*data = 10; // error
	}
};
int main()
{
	A<int> a;
}








