#include <iostream>
#include <mutex>

// CRTP ( Curiously Recurring Template Pattern )

template<typename T>
class Singleton
{
protected:
	Singleton() {} 

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static std::mutex mtx;
	static T* sinstance;  //<<<======
public:
	static T& getInstance() // <<=======
	{
		std::lock_guard<std::mutex> lg(mtx); 

		if (sinstance == nullptr)
			sinstance = new T; // <<======
	
		return *sinstance;
	}
};
template<typename T> T* Singleton<T>::sinstance = nullptr;  // <<=====
template<typename T> std::mutex Singleton<T>::mtx;

// Keyboard 클래스도 힙에 만드는 싱글톤으로 하고 싶다
class Keyboard : public Singleton< Keyboard >
{

};

int main()
{
	Keyboard& k = Keyboard::getInstance();
}
