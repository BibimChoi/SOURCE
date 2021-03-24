#include <iostream>
#include <initializer_list>
class Point
{
	int x, y;
public:
	Point(int a)        { std::cout << "1" << std::endl; }
	Point(int a, int b) { std::cout << "2" << std::endl; }
	Point(std::initializer_list<int> ) { std::cout << "3 " << std::endl; }
};
int main()
{
	Point p1(1);
	Point p2(1,2);
	Point p3{ 1,2 };
	Point p4(1,2,3);
	Point p5{ 1,2,3 };
	Point p6{ 1,2,3 };
}