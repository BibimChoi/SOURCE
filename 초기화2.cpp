#include <initializer_list>

void foo(std::initializer_list<int> e)
{
}
int main()
{
	std::initializer_list<int> e = { 1,2,3,4,5 };
	foo(e);

}