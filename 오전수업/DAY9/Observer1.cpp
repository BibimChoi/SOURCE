// codexpert.org 에서 DAY9.zip 받으시면 됩니다.
// "Debug", "x86"
// "Windows SDK 버전 설정"













//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>

// 모든 그래프의 공통의 인터페이스
struct IGraph
{
	virtual void Update(int n) = 0;
	virtual ~IGraph() {}
};

// 관찰의 대상(Subject)
class Table
{
	std::vector<IGraph*> v; // 핵심. Table 과 연결된 모든 그래프 관리
	int value; 
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}  // v에서 p를 제거..
	
	// data 변경시 연결된 모든 그래프에 전달
	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
	//---------------------------
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;

			notify(value); // 입력값이 변경되었으므로 모든 등록된 그래프에 
							// 통보
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





