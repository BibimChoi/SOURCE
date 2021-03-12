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
	Object o2 = std::move(o1);	// move 생성자 호출.
				// static_cast<Object&&>(o1) ==> move 생성자

	// 핵심 : 상수 객체는 move 될수 없다. 
	//        상수 이므로 자원 포인터가 nullptr 으로 reset 될수 없다.
	const Object o3;
	Object o4 = std::move(o3);	// move 생성자 가 아닌 복사 생성자 호출.
			// static_cast<o3타입&&>(o3) 입니다.
			// static_cast<const Object&&>(o3) 입니다.

}



