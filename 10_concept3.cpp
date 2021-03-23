// 10_concept3
#include <iostream>
#include <vector>

template<typename Iter> 
void sort(Iter first, Iter last)
{
	std::cout << "sort �⺻ ����" << std::endl;
}
template<typename Iter, typename Pred>
void sort(Iter first, Iter last, Pred f)
{
	std::cout << "sort �����ڸ� �޴� ����" << std::endl;
}

template<typename Cont>
void sort(Cont c)
{
	std::cout << "sort �����̳� ����" << std::endl;
}

template<typename Cont, typename Pred>
void sort(Cont c, Pred f)
{
	std::cout << "sort �����̳� ������ ����" << std::endl;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	sort(v.begin(), v.end()); // ����� ���ô�.

	// ����å�� ��ü �����ϰ� ��������.
	sort(v.begin(), v.end(), [](int a, int b) { return a < b; } );

	sort(v); // �����̳ʸ� �޴� ����

	sort(v , [](int a, int b) { return a < b; });
}


