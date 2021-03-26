#include <iostream>
#include <memory>

int main()
{
	int* p = new int;
	std::shared_ptr<int> sp1(p);
	std::shared_ptr<int> sp2(sp1); //

	std::shared_ptr<int> sp2(p);  // 
}