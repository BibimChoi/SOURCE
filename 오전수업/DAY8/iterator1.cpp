// 3_반복자1 - 104 page

// 반복자(iterator) : 복합객체(컨테이너)의 내부구조에 상관없이
//					동일한 방법으로 요소를 열거하게 하자!

// vector는 모든 요소가 연속적으로 놓입니다.
class vector {}; 

// list는 모든 요소가 분리되어 있습니다
class list {};

int main()
{
	vector v = { 1,2,3,4,5,6,7,8,9,10 };
	list   s = { 1,2,3,4,5,6,7,8,9,10 };

	// s, v의 모든 요소를 동일한 방법으로 열거할수 없을까 ?
//	vector 반복자 e = v.GetEnumerator(); // vector에서 반복자 얻기
	list   반복자 e = s.GetEnumerator(); // list 에서 얻기

	// vector반복자건, list 반복자이건... 아래 코드는 동일하게 실행되어야 합니다.
	int n = e.GetObject();  // 첫번째 요소인 1

	e.MoveNext();			// 다음으로 이동
	n = e.GetObject();		// 2번째 요소인 2
}

















