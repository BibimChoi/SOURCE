#include <iostream>
#include <type_traits>

// �Ʒ� �ڵ尡 boost ���̺귯�� �ȿ� �ִ� "cmpressed pair" �Դϴ�.

class Empty {};

// �ᱹ PAIR�� 2���� �κ� Ư��ȭ ������ ����ϰ� �˴ϴ�
// �̰�쿡�� primary template �� ���� ������ �˴ϴ�.
template<typename T, typename U, bool b = std::is_empty_v<T>  >
struct PAIR;


// ������ ���ڿ� ���� ������ �ٸ��� ����.
template<typename T, typename U >
struct PAIR<T, U, false>
{
	T first;
	U second;

	PAIR() = default;
	PAIR(const T& a, const T& b) : first(a), second(b) {}

	T& getFirst()  { return first; }
	U& getSecond() { return second; }
};

template<typename T, typename U >
struct PAIR<T, U, true> : public T
{
	U second;

	PAIR() = default;
	PAIR(const T& a, const T& b) : T(a), second(b) {}

	T& getFirst() { return *this; }
	U& getSecond() { return second; }
};


int main()
{
	PAIR<int, int> p1;
	std::cout << sizeof(p1) << std::endl; // 8

	PAIR<Empty, int> p2;
	std::cout << sizeof(p2) << std::endl; // 4


}
