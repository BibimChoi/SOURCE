#include <iostream>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
	~Car()    { std::cout << "~Car" << std::endl; }
};

// Ptr �� �ٽ��Դϴ�.
// ���� : ������ ��ü�� �ٸ� Ÿ���� ������ ��Ȱ�� �ϴ� ��
// ���� : -> �����ڿ� *�����ڸ� ������ �ؼ� ������ ó�� ���̰� �Ѵ�.
// ���� : Raw Pointer �� �ƴ� ��ü�̴�.
//		����/����/����/�ı��� ��� �������� �߰��� �۾��� �Ҽ� �ִ�
//		��ǥ���� Ȱ���� �Ҹ��ڿ����� �ڿ� �ڵ�����
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}
	
	~Ptr() { delete obj; }

	Car* operator->() { return obj; }
	Car& operator*()  { return *obj; }
};
int main()
{
	Ptr p = new Car;  // Ptr p(new Car)

	p->Go(); //  (p.operator->()) Go() �� ���������
			 //  (p.operator->())->Go() �� �ؼ��˴ϴ�.
	(*p).Go();
}


