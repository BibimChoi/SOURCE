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

	v.resize(7);  // �� ������ ������ ������ ���ô�.

	std::cout << v.size()     << std::endl; // 7
	std::cout << v.capacity() << std::endl; // 10

	v.push_back(0); // ���� �Ѱ� �߰�

	std::cout << v.size()     << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 10

	v.shrink_to_fit(); // ������ �޸� ����

	std::cout << v.size() << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 8


	v.push_back(0); // ���� �Ѱ� �߰�

	std::cout << v.size() << std::endl; // ?
	std::cout << v.capacity() << std::endl; // ?

}





