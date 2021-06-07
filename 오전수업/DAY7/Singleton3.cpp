#include <iostream>
// 오직 한개의 객체를 힙에 만드는 싱글톤.
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

		return *instance;
	}
};
Cursor* Cursor::sinstance = nullptr;





int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
	std::cout << &c1 << ", " << &c2 << std::endl;

}
