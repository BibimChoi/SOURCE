#include <iostream>
#include <vector>


// 변경된 데이타를 Graph(관찰자)에게 어떻게 전달할것인가 ?
// push : Table이 Graph에 전달
// pull : Graph(관찰자)가 Table의 함수를 호출해서 data 얻기.

class Subject;

struct IGraph
{
	virtual void Update(void* hint) = 0;
	virtual ~IGraph() {}

	// 그래프는 1개의 관찰의 대상과 연결된다.
	Subject* pSubject = nullptr;
};


class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p); p->pSubject = this; }
	void detach(IGraph* p) {}

	void notify(void* hint)
	{
		for (auto p : v)
			p->Update(hint);
	}
};

class Table : public Subject
{
	int value;
public:
	int getData() const { return value; }

	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;

			//notify(value);
			notify(0); // 힌트는 없다.!!
		}
	}
};
//----------------------
class BarGraph : public IGraph
{
public:
	void Update(void* hint) override
	{
		int n = 0;

		if (hint != nullptr)
			n = reinterpret_cast<int>(hint);
		else
		{
			// 힌트가 없으므로 Table의 접근해서 데이타를 얻어 온다.
//			n = pSubject->getData();// error. pSubject 는 Subject* 이므로
									// 파생 클래스 고유 멤버에 접근할수 없다
			Table* pTable = static_cast<Table*>(pSubject);

			n = pTable->getData();      

			// MFC의 Document/View,  QT의 MVC 가 관찰자 패턴인데..
			// 캐스팅이 많이 등장합니다.
		}


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





