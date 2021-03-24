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
// bool 을 보관하는 Vector 는 specialization 버전 사용
template<> class Vector<bool>
{
	int* buff;
public:
	Vector(std::size_t sz, T value)
	{
		buff = new int[sz/32 + 1];
	}
	// [] 연산자는 비트를 반환할수 있어야 합니다.
	// Bit 반환을 위한 Proxy
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

	auto& r1 = v1[0]; // ok.    v1[0] 은 임시객체 아님.
	auto& r2 = v2[0]; // error. v2[0] 은 임시객체 반환.
}




