#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {  }
};

int main()
{
	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);

	// make_shared �� ��ǥ���� 2���� ����
	// 1. �޸��� ȿ����( ��ü + ������ü�� �ѹ��� �Ҵ�)
	// 2. ���� ������

	foo(std::shared_ptr<Point>(new Point(1, 2)), goo());
}

void foo(std::shared_ptr<Poit> sp, int a ) {}

int goo() { return 0; }








