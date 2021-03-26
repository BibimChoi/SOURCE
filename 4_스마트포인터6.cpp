#include <iostream>
#include <memory>

void foo(int* p) { free(p); }

int main()
{
	// 삭제자 변경
	std::shared_ptr<int>  sp1(new int); // sp1 이 파괴될때 delete.


//	std::shared_ptr<int>  sp2(static_cast<int*>(malloc(100)), foo );
//	std::shared_ptr<int>  sp2(static_cast<int*>(malloc(100)), free );
	std::shared_ptr<int>  sp2(static_cast<int*>(malloc(100)), [](int* p) { free(p); });

	// 배열 버전
	std::shared_ptr<int>  sp3(new int[100]); // 버그, delete 가 아닌 delete[] 해야 합니다.
	std::shared_ptr<int>  sp3(new int[100], [](int* p) { delete[] p; } ); // ok

	// C++17 부터 아래 처럼 가능.
	std::shared_ptr<int[]>  sp3(new int[100]); // ok

	// 그런데, int[100] 가 필요 하면 왜 스마트포인터를 사용하는가 ?
	// vector<int> v(100)

	// make_shared 와 삭제자
	// std::make_shared<int>(10) : 항상 operator new로 자원 할당.
	//							즉, 자원할당 방법을 변경할수 없다.
	std::shared_ptr<int>  sp3 = std::make_shared<int>(10);

//	std::allocator<int> ax;
//	std::shared_ptr<int>  sp3 = std::allocate_shared<std::allocator, int>(ax, 10);
}










