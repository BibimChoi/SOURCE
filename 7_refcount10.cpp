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

// Ŭ���� ���ø� ����� Ÿ�� ���� T�� ������� ���� ��� �Լ���
// ���ø��� �ƴ� ��� Ŭ������ �����ؼ� ��ӹް� ����.
// "thin template" �Ǵ� "template hoisting" �̶�� �̸��� ���� ���
class RefCountBase
{
protected:
	mutable int refCount = 0;
public:
	void AddRef()  const { ++refCount; }

protected:
	~RefCountBase() { std::cout << "~RefCountBase" << std::endl; }
};

// std::default_delete<T> : ǥ�ؿ� �ִ� �޸� ���� �Լ� ��ü
//							���������� delete�� ����.
template<typename T, typename Del = std::default_delete<T> >
class RefCount : public RefCountBase
{
public:
	void Release() const
	{
		if (--refCount == 0)
		{
		//	delete static_cast<const T*>(this);

			Del d; // ������ �Լ���ü
			//d( static_cast<const T*>(this) );	 // ������ �̷��� �ȵǰ�		
			d(static_cast<T*>(const_cast<RefCount*>(this)));	 // �̷��� �ؾ� �մϴ�.
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







