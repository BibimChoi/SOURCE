#include <iostream>
using namespace std;

struct ISharedMemory
{
	virtual void* Alloc() = 0;
	virtual void Free() = 0;
};
class Win32SharedMemory : public ISharedMemory
{
public:
	virtual void* Alloc() {}
	virtual void Free() {}
};
class LinuxSharedMemory : public ISharedMemory 
{
public:
	virtual void* Alloc() {}
	virtual void Free() {}
};
//---------------------
// SharedMemory 로 부터 파생된 자료구조를 구축하려고합니다.
class LinuxStack : public LinuxSharedMemory
{
};
class LinuxList : public LinuxSharedMemory
{
};
class WindowStack : public Win32SharedMemory
{
};
class WindowList : public Win32SharedMemory
{
};
//------------------------
// ISharedMemory 를 직접 사용하지 말고
// 추상층을 제공한다.
class SharedMemory
{
	ISharedMemory* pImpl;
public:
	void* Alloc() { return pImpl->Alloc(); }
	void Free(void* p) { pImpl->Free(p); }
};
//이제 다양한 파생 클래스는 SharedMemory 로 부터만 상속받으면 됩니다.
class Stack : public SharedMemory
{
};









