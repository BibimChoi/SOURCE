#include <iostream>
#include <vector>
#include "IGraph.h"  

#define USING_GUI
#include "cppmaster.h"

class Subject
{
	std::vector<IGraph*> v;
public:
	void ReloadGraph()
	{
		v.clear();
		ec_enum_files("D:\\CPP_DP", "*.dll", LoadGraph, this);
	}
	
	// DLL을 찾을때 마다 아래 함수가 호출됩니다.
	static int LoadGraph(std::string name, void* p)
	{
		Subject* self = static_cast<Subject*>(p);

		std::cout << name << " 찾음 " << std::endl;

		void* addr = ec_load_module(name);

		typedef IGraph*(*F)();

		F f = (F)ec_get_function_address(addr, "CreateGraph");

		IGraph* g = f(); // 그래프 객체생성(플러그인 객체)
		//------------------------------
		self->attach(g);

		return 1; // 계속 찾아라!!
		// return 0; // 그만 찾아라!!
	}
	Subject() { ReloadGraph(); }








	virtual ~Subject() {} 

	void attach(IGraph* p) { v.push_back(p); }
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





