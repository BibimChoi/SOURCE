#include "cppmaster.h"
#include <vector>

/*
class DBConnect {};

int main()
{
	std::vector<int> v(10);

	v.resize(7);
	v.resize(8);
}
*/
int main()
{
	std::vector<int> v(10, 3);

	v.resize(7);  // 이 순간의 원리를 생각해 봅시다.

	std::cout << v.size()     << std::endl; // 7
	std::cout << v.capacity() << std::endl; // 10

	v.push_back(0); // 끝에 한개 추가

	std::cout << v.size()     << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 10

	v.shrink_to_fit(); // 여분의 메모리 제거

	std::cout << v.size() << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 8


	v.push_back(0); // 끝에 한개 추가

	std::cout << v.size() << std::endl; // ?
	std::cout << v.capacity() << std::endl; // ?

}





