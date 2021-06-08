// static4.cpp

// 아래 코드에서 에러가 나오는 부분을 찾으세요
class A
{
	int data;
public:
	void foo()
	{
		*data = 10;
	}
};
int main()
{
	A a;
}
