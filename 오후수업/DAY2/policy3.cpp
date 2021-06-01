// 방법 2. 변하는 것을 다른 클래스로( strategy 패턴)

// 장점 : 동기화 정책을 담은 클래스는 다른 클래스에서도 사용가능

// 단점 : 인터페이스를 사용하므로 가상함수 이다.
//			함수 호출시 약간의 오버헤드가 있다.

struct ILock
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ILock() {}
};
template<typename T> class List
{
	ILock* pLock = nullptr;
public:
	void setLock( ILock* p ) { pLock = p; }

	void push_front(const T& a)
	{
		if (pLock) pLock->lock();
		//......
		if (pLock) pLock->unlock();
	}
};
List<int> st; 

int main()
{
	st.push_front(10);
}




