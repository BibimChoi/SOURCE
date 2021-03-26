#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<int> up1(new int);
	//std::unique_ptr<int> up2 = up1; // error
	std::unique_ptr<int> up3 = std::move(up1); // ok..

	// 다음중 에러를 모두 고르세요
	std::shared_ptr<int> sp(new int);
	std::unique_ptr<int> up(new int);

	std::shared_ptr<int> sp1 = up;				// 1
	std::shared_ptr<int> sp2 = std::move(up);	// 2

	std::shared_ptr<int> up1 = sp;				// 3
	std::shared_ptr<int> up2 = std::move(sp);	// 4

}