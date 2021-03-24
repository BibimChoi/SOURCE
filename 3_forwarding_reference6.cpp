#include <vector>

template<typename T> class Vector
{
	T* buff;
public:
	Vector(std::size_t sz, T value)
	{
		buff = new T[sz];
	}
	T& operator[](int idx) { return buff[idx]; }
};
// bool �� �����ϴ� Vector �� specialization ���� ���
template<> class Vector<bool>
{
	int* buff;
public:
	Vector(std::size_t sz, T value)
	{
		buff = new int[sz/32 + 1];
	}
	// [] �����ڴ� ��Ʈ�� ��ȯ�Ҽ� �־�� �մϴ�.
	// Bit ��ȯ�� ���� Proxy
	struct BitProxy
	{
		int* buff;
		int idx;

		BitProxy(int* buff, int idx) : buff(buff), idx(idx) {}
	};
	   

	bool& operator[](int idx) { return BitProxy(buff, idx); }
};


int main()
{
	Vector<int>  v1(10, 3);
	Vector<bool> v2(10, false);

	auto& r1 = v1[0]; // ok.    v1[0] �� �ӽð�ü �ƴ�.
	auto& r2 = v2[0]; // error. v2[0] �� �ӽð�ü ��ȯ.
}




