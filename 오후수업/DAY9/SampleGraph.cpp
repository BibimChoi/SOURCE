// SampleGraph.cpp
#include <iostream>
#include "IGraph.h"

// BarGraph 복사해 오세요.  클래스 이름을 SampleGraph로 변경하세요

class SampleGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Sampe Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "=";

		std::cout << std::endl;
	}
};

// 그래프 DLL은 미래에 만들어질수도 있기때문에
// 그래프 클래스 이름은 사용자가 알수 없습니다.
// 그래프 객체를 만드는 함수는 DLL안에 있어야 합니다.
extern "C" __declspec(dllexport)
IGraph* CreateGraph()
{
	return new SampleGraph;
}

// vs2017 개발자 명령프롬프트(develop command prompt) 실행하세요.

// 현재 폴더로 이동후에

// cl SampleGraph.cpp   /LD 

//  /LD  : DLL로 빌드하는 옵션

// 완성된 DLL을 약속된 폴더에 놓으세요. 
// 강의에서는 "D:\\CPP_DP\\SampleGraph.dll" 사용










