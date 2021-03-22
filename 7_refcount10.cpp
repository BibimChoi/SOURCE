#include <iostream>
#include <vector>


template<typename T>
class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p) { if (obj) obj->AddRef(); }
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }
	~AutoPtr() { if (obj) obj->Release(); }

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

// 클래스 템플릿 설계시 타입 인자 T를 사용하지 않은 멤버 함수는
// 템플릿이 아닌 기반 클래스를 설계해서 상속받게 하자.
// "thin template" 또는 "template hoisting" 이라는 이름을 가진 기술
class RefCountBase
{
protected:
	mutable int refCount = 0;
public:
	void AddRef()  const { ++refCount; }

protected:
	~RefCountBase() { std::cout << "~RefCountBase" << std::endl; }
};

// std::default_delete<T> : 표준에 있는 메모리 해제 함수 객체
//							내부적으로 delete로 삭제.
template<typename T, typename Del = std::default_delete<T> >
class RefCount : public RefCountBase
{
public:
	void Release() const
	{
		if (--refCount == 0)
		{
		//	delete static_cast<const T*>(this);

			Del d; // 삭제용 함수객체
			//d( static_cast<const T*>(this) );	 // 이제는 이렇게 안되고		
			d(static_cast<T*>(const_cast<RefCount*>(this)));	 // 이렇게 해야 합니다.
		}
	}
};

class Truck : public RefCount< Truck  >
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
//	AutoPtr<Truck> p = new Truck;
	AutoPtr<Truck> p = static_cast<Truck*>( malloc(sizeof(Truck))) ;

}







