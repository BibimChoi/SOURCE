// ICalc.h 
#pragma once

// 참조계수용 함수는 모든 종류의 Proxy 에서 사용될수 있다.
// 기반 클래스(인터페이스)로 제공하자.
struct IRef
{
	// Proxy 객체를 참조계수로 관리하기로 했다면
	// 참조계수 관련 함수는 인터페이스에 있어야 합니다.
	virtual void AddRef()  const = 0;
	virtual void Release() const = 0;

	virtual ~IRef() {}
};
// 이제, 다양한 종류의 Proxy 인터페이스 만들때 IRef에서 상속받으세요
struct ICalc : public IRef
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};
