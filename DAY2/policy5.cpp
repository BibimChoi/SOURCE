// STL 의 원리
template<typename T, typename Ax = std::allocator<T> >
class vector
{
	T* buff;
	Ax ax;  // 메모리 할당 정책을 담은 메모리 할당기
public:
	void resize(int n)
	{
		// 버퍼 크기가 부족해서 다시 할당하려고 합니다.
		// 어떻게 할당할까요 ?
		// C++에서는 메모리를 할당하는 방법이 아주 많이 있습니다.
		// new / malloc / system call / windows api/ 풀링 
		//buff = new T[n];

		// 메모리 관련 작업은 할당기를 사용합니다.
		buff = ax.allocate(n); //
		ax.deallocate(buff, n); // 메모리 해지
	}
};

