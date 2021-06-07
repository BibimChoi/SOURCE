#include <iostream>
#include <mutex>

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static std::mutex mtx;
	static Cursor* sinstance;
public:
	static Cursor& getInstance()
	{
		mtx.lock();

		if (sinstance == nullptr)
			sinstance = new Cursor;

		mtx.unlock();
		return *instance;
	}
};
Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;





int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
	std::cout << &c1 << ", " << &c2 << std::endl;

}
