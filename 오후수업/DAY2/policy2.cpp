// 방법 1. 변하는 코드는 가상함수로 ( template method )
// => 동기화 정책은 List 뿐아니라 vector, map 등도 필요 하다!!! 
// => 아래 처럼 하면 재사용할수 없다
template<typename T> class List
{
public:
	void push_front(const T& a)
	{
		lock();
		//......
		unlock();
	}
	// 아래 처럼하면 동기화되지 않습니다.
	// 동기화 되게 하려면 상속받은후 lock/unlock을 재정의하면 됩니다
	virtual void lock() {}
	virtual void unlock() {}
};

List<int> st; 

int main()
{
	st.push_front(10);
}




