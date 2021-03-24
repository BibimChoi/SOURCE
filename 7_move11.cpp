#include <iostream>
#include <string>
#include <vector>
#include "cppmaster.h"

class Data
{
public:
	Data() = default;
	Data(const Data& d) { LOG_FUNCTION_NAME(); }
	Data& operator=(const Data&) { LOG_FUNCTION_NAME(); return *this; }
	Data(Data&& d) { LOG_FUNCTION_NAME(); }
	Data& operator=(Data&&) { LOG_FUNCTION_NAME(); return *this; }
};
// 중요합니다. 꼭 알아 두세요.
class Test
{
	Data data;
public:
	// setter를 만들어 봅시다.
	// 1. call by value : 복사본의 오버헤드가 있다.
	// void setData(Data d) { data = d; }

	// 2. const lvalue reference : C++98 시절에 최선의 코드!!! 아주 널리 사용
//	void setData(const Data& d) { data = d; } // 항상 복사
//	void setData(const Data& d) { data = std::move(d); } // 역시 항상 복사, const 객체

	// 3. C++11 에서의 최선의 코드 - 2개의 setter를 만들어라
	// "복사생성자 와 move 생성자"를 만드는 것 처럼
	// "복사 setter"와 "move setter"를 각각 만들어라
	void setData(const Data& d) { data = d; }
	void setData(Data&& d)      { data = std::move(d); }
};

int main()
{
	Data d;

	Test test;
	test.setData(d);
	test.setData( std::move(d) );
}








