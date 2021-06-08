#include <iostream>
#include <mutex>

// CRTP ( Curiously Recurring Template Pattern )

// 기반 클래스에서 미래에 만들어질 파생 클래스 이름을 사용하는 기술

template<typename T> class Singleton
{
protected:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static std::mutex mtx;
	static T* sinstance;   // <<===========
public:

	static T& getInstance() // <<=================
	{
		std::lock_guard<std::mutex> lg(mtx); 

		if (sinstance == nullptr)
			sinstance = new T; // <<===============

		return *sinstance;
	}
};
template<typename T> T* Singleton<T>::sinstance = nullptr; // <<==============
template<typename T> std::mutex  Singleton<T>::mtx;

// Keyboard 클래스도 싱글톤으로 하고 싶습니다.!!

class Keyboard : public Singleton < Keyboard > 
{

};
int main()
{
	Keyboard& k1 = Keyboard::getInstance();
}
