#include <iostream>
#include <vector>


struct IGraph
{
	virtual void Update(int n) = 0;
	virtual ~IGraph() {}
};

// 관찰에 대상(Table)이 가진 데이타에 무관하게 관찰자 패턴의 기본 로직은 동일하다
// 관찰자 패턴의 기본 로직을 제공하는 기반 클래스를 설계 한다.
class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {} 

	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
};
// 디자인 패턴에서는 아래 Table을 "Concrete Subject"
class Table : public Subject
{
	int value;
public:
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;

			notify(value);
		}
	}
};
//----------------------
class BarGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};
class PieGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << ")";

		std::cout << std::endl;
	}
};
int main()
{
	Table t;
	BarGraph bg; t.attach(&bg);
	PieGraph pg; t.attach(&pg);
	t.edit();
}





