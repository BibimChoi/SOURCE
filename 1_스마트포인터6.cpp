#include <iostream>
#include <memory>

void foo(void* p) { free(p); }

int main()
{
	// 삭제자 변경
	std::shared_ptr<int>  sp1( new int ); // sp1이 파괴될때 delete 수행

//	std::shared_ptr<int>  sp2(static_cast<int*>(malloc(100)), foo );
								// sp2가 파괴될때 등록된 함수 호출
//	std::shared_ptr<int>  sp2(static_cast<int*>(malloc(100)), free );

	std::shared_ptr<int>  sp2(static_cast<int*>(malloc(100)), [](int* p) { free(p); } );

	// 배열의 경우
	std::shared_ptr<int>  sp3(new int[10], [](int* p) { delete[] p; } ); // C++11스타일

	std::shared_ptr<int[]>  sp4(new int[10]); // C++17 부터 지원

	// 동적할당된 int[10] 필요하다면 ? => 왜 스마트포인터 사용하는가 ?
	//std::vector<int> v(10); 

}







