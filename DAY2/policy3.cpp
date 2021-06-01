// 방법 2. 변하는 것을 다른 클래스로 - strategy

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
	void setLock(ILock* p) { pLock = p; }

	void push_front(const T& a)
	{
		if (pLock) pLock->lock();
		//......
		if (pLock) pLock->unlock();
	}
};
// 동기화 정책을 담은 클래스를 만들어서 사용합니다.
class MutexLock : public ILock
{
	// pthread_mutex_t ...
public:
	void lock()   override { std::cout << "lock" << std::endl; }
	void unlock() override { std::cout << "unlock" << std::endl; }
};
List<int> st; 

int main()
{
	MutexLock ml;
	st.setLock(&ml);


	st.push_front(10);
}




