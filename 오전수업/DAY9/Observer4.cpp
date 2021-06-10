#include <iostream>
#include <vector>


// Table 이 변경된 사실을 그래프에 알릴때
// 변경된 데이타의 정보도 전달해야 한다.
// push : Table 이 그래프(관찰자)전달
// pull : 그래프(관찰자)가 Table에 접근해서 가져가는 방식

class Subject;

struct IGraph
{
	virtual void Update(int n) = 0;
	virtual ~IGraph() {}

	// 모든 그래프는 자신이 연결된 Table을 알아야 한다
	Subject* pSubject = nullptr;
};

class Subject	
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p); p->pSubject = this; }
	void detach(IGraph* p) {}

	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
};

class Table : public Subject
{
	int value;
public:
	int getData() const { return value; }
	// 여러개의 getter가 있어도 됩니다.

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
		// 1. Table에서 데이타가 변경되었다고 이함수를 호출.
		// 2. 이제 그래프에서는 Table에 접근해서 데이타를 얻은후에 출력하면됩니다.

		//int data = pSubject->getData(); // error. pSubject 는 기반 클래스인 Subject* 이므로
									// Table 고유의 멤버에 접근 할수 없습니다.
									// 캐스팅 필요

		Table* pTable = static_cast<Table*>(pSubject); // MFC나 QT 등의 라이브러리가
		int data = pTable->getData();				   // 이런 캐스팅이 많이 있습니다.			

		// 이제 얻어온 Data를 사용해서 그림을 그립니다.



		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};

int main()
{
	Table t;
	BarGraph bg; t.attach(&bg);
	t.edit();
}





