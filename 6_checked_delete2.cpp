#include <iostream>

template<typename T>
struct default_delete
{
	inline void operator()(T* p) const
	{
		static_assert(sizeof(T) > 0, "Error, delete imcomplete type");
		std::cout << "delete" << std::endl;
		delete p;
	}
};

int main()
{
	int* p = new int;

	std::default_delete<int> d;
	d(p); // delete 

}