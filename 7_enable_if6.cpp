// 7_enable_if6
#include <iostream>
#include <type_traits>

template<typename T> class Point
{
	T x;
	T y;
public:
	Point(T a, T b) : x(a), y(b) {}
};

int main()
{
	Point<double> p1(2.1, 3.4);
	Point<int> p2(1, 2);

	Point<double> p3 = p1; // ok
	Point<double> p4 = p2; // 되는게 좋을까요 ? 안되는게 좋을까요 ?

}