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
};

void foo(default_delete<Dog> d)
{
	Dog* p = new Dog;
	d(p);  // Dog를 지우는 삭제자
}

int main()
{
	default_delete<Dog> d;
	foo(d);
}
