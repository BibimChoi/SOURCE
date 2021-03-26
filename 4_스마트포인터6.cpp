#include <iostream>
#include <memory>

void foo(int* p) { free(p); }

int main()
{
	// ������ ����
	std::shared_ptr<int>  sp1(new int); // sp1 �� �ı��ɶ� delete.


//	std::shared_ptr<int>  sp2(static_cast<int*>(malloc(100)), foo );
//	std::shared_ptr<int>  sp2(static_cast<int*>(malloc(100)), free );
	std::shared_ptr<int>  sp2(static_cast<int*>(malloc(100)), [](int* p) { free(p); });

	// �迭 ����
	std::shared_ptr<int>  sp3(new int[100]); // ����, delete �� �ƴ� delete[] �ؾ� �մϴ�.
	std::shared_ptr<int>  sp3(new int[100], [](int* p) { delete[] p; } ); // ok

	// C++17 ���� �Ʒ� ó�� ����.
	std::shared_ptr<int[]>  sp3(new int[100]); // ok

	// �׷���, int[100] �� �ʿ� �ϸ� �� ����Ʈ�����͸� ����ϴ°� ?
	// vector<int> v(100)

	// make_shared �� ������
	// std::make_shared<int>(10) : �׻� operator new�� �ڿ� �Ҵ�.
	//							��, �ڿ��Ҵ� ����� �����Ҽ� ����.
	std::shared_ptr<int>  sp3 = std::make_shared<int>(10);

//	std::allocator<int> ax;
//	std::shared_ptr<int>  sp3 = std::allocate_shared<std::allocator, int>(ax, 10);
}










