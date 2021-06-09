// codexpert.org 에서 DAY9.zip 받으시면 됩니다.
// "Debug", "x86"
// "Windows SDK 버전 설정"













//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>

struct IGraph
{
	virtual void Update(int n) = 0;
	virtual ~IGraph() {}
};


// Table이 다루는 데이타의 형태에 상관없이 관찰자 로직은 동일 합니다.
// 관찰자 패턴의 로직만 제공하는 기반 클래스를 제공합니다
class Subject	// 관찰자 로직을 제공하는 기반클래스
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
// 다양한 종류의 Table을 만들때.. 
// Subject에서 상속 받으면 됩니다.
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





