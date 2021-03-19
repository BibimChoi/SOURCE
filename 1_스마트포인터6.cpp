#include <iostream>
#include <memory>

void foo(void* p) { free(p); }

int main()
{
	// 삭제자 변경
	std::shared_ptr<int>  sp1(new int); // delete 사용해서 자원 해지

	// new가 아닌 방법을 사용하면 생성자의 2번째 인자로 삭제자 전달
	// 소멸자에서 "삭제자 함수 호출"
	std::shared_ptr<int>  sp2(static_cast<int*>(malloc(100)), foo);
	std::shared_ptr<int>  sp2(static_cast<int*>(malloc(100)), free);
	std::shared_ptr<int>  sp2(static_cast<int*>(malloc(100)), 
												[](int* p) { free(p); }	);

	// 배열의 경우
//	std::shared_ptr<int>    sp5(new int[10]); // 결국 int* p = new int[10];
											// delete p; 입니다. "미정의 동작 발생"

	std::shared_ptr<int>    sp5(new int[10], [](int* p) { delete[] p; } ); //C++11
	std::shared_ptr<int[]>  sp6(new int[10]); // C++17 부터는 이렇게만 하면 
												// 소멸자에서 delete[] 사용
	// new int[10] 가 필요하면 왜 스마트 포인터로 관리하는가 ? vector가 있는데!!
	//std::vector<int> v(10);
}







