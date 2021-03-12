// 105 page.. 상수 객체와 move
#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }
	Object(Object&&) noexcept  {std::cout << "move" << std::endl;	}
};
int main()
{
	Object o1;
	Object o2 = std::move(o1);	// move 생성자 호출
			// static_cast<Object&&>(o1) 


	const Object o3; // 상수객체
	Object o4 = std::move(o3); // 복사 생성자 호출
					// 상수객체는 move될수 없다.

					// static_cast<o3타입&&>(o3)

					// static_cast<const Object&&>(o3) 

}





