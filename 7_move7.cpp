
#include <iostream>
#include <string>

class Object
{
public:
	std::string name;

	Object(std::string name) : name(name) {}
};
int main()
{
	Object o1("hello");
	Object o2 = o1;
//	Object o2 = std::move(o1);

	std::cout << o1.name << std::endl;
}
