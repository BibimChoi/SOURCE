#include <iostream>

class Animal {};
class Dog : public Animal {};

template<typename T>
struct default_delete
{
	inline void operator()(T* p) const
	{
		static_assert(sizeof(T) > 0, "Error, delete imcomplete type");
		delete p;
	}
	
	// generic 복사생성자
	template<typename U,
		     typename = std::enable_if_t< std::is_constructible_v<U*, T*> >>
	default_delete(const default_delete<U>&) {}

	default_delete() = default;
};
void foo(default_delete<Dog> d) // default_delete<Dog> d = default_delete<int>
{
	Dog* p = new Dog;
	d(p);  // Dog를 지우는 삭제자
}
int main()
{
	//default_delete<Dog> d;
	default_delete<Animal> d; // operator()(Animal* p) 의 모양임.
	foo(d);
}
