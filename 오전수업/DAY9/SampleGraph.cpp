// SampleGraph.cpp
#include <iostream>
#include "IGraph.h"

// BarGraph 복사해오세요.
class SampleGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Sample Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "+";

		std::cout << std::endl;
	}
};

// 그래프 클래스는 나중에 추가될수 있으므로.. 
// 이 DLL사용자는 그래프 클래스 이름을 알수 없다.
// 약속된 함수를 통해서 그래프를 생성한다.
extern "C" __declspec(dllexport)
IGraph* CreateGraph()
{
	return new SampleGraph;
}

// cl SampleGraph.cpp  /LD  

// /LD  : DLL로 빌드하라는 명령..
// DLL 빌드후에 "약속된 디렉토리에 DLL을 넣어 두면 됩니다."

// 강의에서는
// D:\CPP_DP\SampleGraph.dll



