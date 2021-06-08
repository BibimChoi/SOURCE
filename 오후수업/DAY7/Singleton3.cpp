// codexpert.org에서 DAY7.zip 받으세요
// gibhub.com/codenuri/SOURCE    오후수업/DAY7/singleton1~2, helper.h 받아 두세요
// 싱글톤3.cpp 입니다.  1번 복사해 오세요.


#include <iostream>

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sinstance;
public:
	static Cursor& getInstance()
	{
		if (sinstance == nullptr)
			sinstance = new Cursor;

		return instance;
	}
};
Cursor* Cursor::sinstance = nullptr;




int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << ", " << &c2 << std::endl;
}








