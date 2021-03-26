#include <iostream>
#include <type_traits>

// �Ʒ� �ڵ尡 boost ���̺귯�� �ȿ� �ִ� "cmpressed pair" �Դϴ�.

class Empty {};



template<typename T, typename U >
struct PAIR
{
	// attribute : C++11 ���� �߰��� ����. �����Ϸ����� �����ϴ� ��
	//			 [[ ��ɾ�  ]]
	// C++20 ���� �߰��� "no_unique_address" ��� attribute 
	[[no_unique_address]] T first;
	[[no_unique_address]] U second;

	PAIR() = default;
	PAIR(const T& a, const T& b) : first(a), second(b) {}

	T& getFirst() { return first; }
	U& getSecond() { return second; }
};





int main()
{
	PAIR<int, int> p1;
	std::cout << sizeof(p1) << std::endl; // 8

	PAIR<Empty, int> p2;
	std::cout << sizeof(p2) << std::endl; // 4


}
