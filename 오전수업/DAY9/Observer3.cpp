// SampleGraph.cpp 소스 만들어 보세요.. BarGraph 복사하세요
#include <iostream>
#include <vector>
#include "IGraph.h" // 이 안에 인터페이스가 있습니다.

#define USING_GUI
#include "cppmaster.h"

class Subject	
{
	std::vector<IGraph*> v;
public:

	// Table이 처음 만들어 질때 약속된 디렉토리에 있는 모든 DLL을 검색해서 Load후에 
	// Graph를 Table에 부착합니다.
	Subject()
	{
		ec_enum_files("D:\\CPP_DP", "*.dll", LoadModule, this);
	}

	// 이제 파일을 찾을때 마다 아래 함수가 호출됩니다. DLL이 10개면 10번 호출
	static int LoadModule(std::string name, void* p)
	{
		Subject* self = static_cast<Subject*>(p);

		std::cout << name << " 을 찾음" << std::endl;

		void* addr = ec_load_module(name.c_str());

		typedef IGraph*(*F)();
		F f = (F)ec_get_function_address(addr, "CreateGraph");

		IGraph* g = f(); // 그래프 생성

		self->attach(g); // 멤버 함수 호출이므로 this 필요..!!

		return 1; // 계속 찾으라는 것
//		return 0; // 검색 중지				 
	}




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





