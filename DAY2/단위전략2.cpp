// 방법 1. template method 사용
// => 동기화는 list 뿐 아니라 vector, set 등 모든 컨테이너에서 필요 하다.
// => template method는 정책의 재사용성을 할수 없다.
template<typename T> class List
{
public:
	void push_front(const T& a)
	{
		lock();
		//......
		unlock();
	}
	// 아래 처럼 아무일도 하지 않으면 동기화되지는 않는다.
	// 동기화가 필요하면 List 파생 클래스를 만들어서 lock/unlock을 override 하면 된다
	virtual void lock() {}
	virtual void unlock() {}
};
List<int> st; 

int main()
{
	st.push_front(10);
}




