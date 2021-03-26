#include <iostream>
#include <vector>

// 연속된 메모리의 버퍼를 받아서 사용하고 싶다.
// string_view 처럼, 버퍼를 가지지 말고,
// 포인터와 갯수만 가지만 읽을수 있다.
// string_view 와 동일한 array_view 를 제공하기로 했다가.. 
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
