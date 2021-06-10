#include <iostream>
#include <vector>

// 관찰자(Observer)패턴
// 객체간 1:N 의 관계를 설정하고, 한개의 객체(Table, Subject, 관찰의 대상)가
// 변경되면 등록된 모든 관찰자(Observer, Graph) 객체에게 통보한다.


struct IGraph
{
	virtual void Update(int n) = 0;
	virtual ~IGraph() {}
};

class Table
{
	std::vector<IGraph*> v;
	int value; 
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {} // 그래프 제거.
	
	// 등록된 모든 그래프에게 통보(Update 호출) 한다.
	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;

			// data 가 변경되었으므로 모든 그래프에게 통보 한다.
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





