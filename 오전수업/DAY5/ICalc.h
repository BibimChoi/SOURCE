// ICalc.h
#pragma once

// 모든 Proxy 를 참조계수로 관리한다고 했다면
// Proxy 의 종류에 상관없이 모든 Proxy 인터페이스는 참조계수가 필요 합니다.
// 참조계수 함수를 위한 인터페이스를 설계 합니다.
struct IRef
{
	// 참조계수로 Proxy를 관리하는 경우 참조계수 관련 함수는 인터페이스 안에
	// 포함되어야 합니다.
	virtual void AddRef() const = 0;
	virtual void Release() const = 0;
	virtual ~IRef() {}
};

// 이제 모든 Proxy 의 인터페이스는 IRef 로 부터 파생되어야 합니다.
struct ICalc : public IRef
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};


