#include <iostream>
#include <vector>

// ���ӵ� �޸��� ���۸� �޾Ƽ� ����ϰ� �ʹ�.
// string_view ó��, ���۸� ������ ����,
// �����Ϳ� ������ ������ ������ �ִ�.
// string_view �� ������ array_view �� �����ϱ�� �ߴٰ�.. 
void foo( std::vector<int>& p) 
{
}

int main()
{
	int x[10] = { 1,2,3 };
	std::vector<int> v = { 1,2,3};

	foo(x);
	foo(v);

}
