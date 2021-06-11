struct sample
{
	// explicit 생성자 : 복사 초기화는 사용할수 없고, 직접 초기화만 가능하게 한다.
	explicit sample() = default;
};

void foo(sample s) {} // sample s = s1
					  // sample s = {}

int main()
{
	// sample 객체를 만드는 법
	sample s1;   // 모든 멤버 데이타가 쓰레기값,
	sample s2{}; // C++11 부터 가능한 표기법. 모든 멤버 데이타가 0
				 // direct initialization

	sample s3 = {}; // C++11부터 가능.  생성자가 explicit 라면 error
					// copy initialization


	foo(s1);
	foo({}); // 이 부분을 생각해 봅시다... 생성자가 explicit 라면 error
}
