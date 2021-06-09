// 3_반복자1 - 104 page

// vector는 모든 요소가 연속적으로 놓입니다.
class vector {}; 

// list는 모든 요소가 분리되어 있습니다
class list {};

int main()
{
	vector v = { 1,2,3,4,5,6,7,8,9,10 };
	list   s = { 1,2,3,4,5,6,7,8,9,10 };

	// C언어         : 컨테이너의 내부구조에 따라 열거하는 방법이 다르다!
	// iterator 패턴 : 컨테이너의 내부구조에 상관없이 동일한 방법으로 열거
	// (열거자(enumerator) 라고도 합니다.)

	// s, v의 모든 요소를 동일한 방법으로 열거할수 없을까 ?

//	list반복자*   p = s.GetEnumerator();
	vector반복자* p = v.GetEnumerator();

	int = p->GetObject();	// 요소 얻기   1
	p->MoveNext();			// 이동

	int = p->GetObject();	// 요소 얻기    2
	
}

