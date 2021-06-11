// 핵심 정리.
// 1. 공통성과 가변성의 분리
//    변하지 않은 코드에서 변하는 코드를 분리

/// A. 변하는 것을 가상함수로 => 파생 클래스에서 가상함수 재정의 하면 변하는 것을 만들수 있다.
///    1. template method
///    2. factory method

/// B. 변하는 것을 다른 클래스로...
///    1. strategy : 객체가 사용하는 알고리즘의 변경 ( Edit/IValidator )
///    2. state    : 객체의 상태에 따라 동작 변경(Character 가 Item 획득시 동작(run, attack) 변경)
///    3. builder  : 복잡한 객체를 만드는데 동일한 공정을 사용하는데, 각 공정의 결과가 다를때

// 2. 재귀적 포함을 사용하는 디자인 패턴

///  1. Composite : 재귀적 포함을 사용한 복합객체 만들기( PopupMenu/MenuItem, Folder/File, MacroCommand )
///  2. Decorator : 재귀적 포함을 사용해서 객체에 기능추가( 파일쓰기 => "압축해서" 파일에 쓰기)


// 3. 간접층의 원리

/// 1. Adapter : 중간층을 사용한 인터페이스의 변경(인터페이스의 불일치 해결) 
/// 2. facade  : 하위시스템의 복잡함을 단순화 하는 포괄적 개념의 상위 시스템 제공(TCPServer), 쉽게사용..
/// 3. Bridge  : 중간층을 도입해서 구현과 추상의 상호 독립적인 Update(PIMPL)
/// 4. Proxy   : 대행자를 만들어서 다양한 기능을 추가( CalcProxy 만들기 예제, IPC)

// 4. 복합객체
/// 1. iterator : 복합객체의 내부구조에 상관없이 동일한 방식으로 열거 ( 인터페이스기반, STL 방식 )
/// 2. visitor  : 복합객체의 내부구조에 상관없이 동일한 방식으로 연산( s.Accept( &TwiceVisitor ))


// 5. ETC
/// 1. Command : 명령을 캡슐화 해서 Undo/Redo 구현
/// 2. Memento : 객체의 상태를 저장했다가 복구하는 패턴.

/// 3. Observer : 객체의 관계를 1 : N으로 설정하고, 객체의 변화를 연결된 다른 모든 객체에 전달
/// 4. Chain Of Responsibility : 발생된 이벤트를 처리할 객체를 만날때 까지 고리에 따라 이동.

/// 5. flyweight : 속성이 동일한 객체는 공유 하자. ( Image 예제 )

// GoF's 패턴 책에는   ( GoF : Gangs Of Four)
// 모든 패턴을 3가지 종류로 구별 합니다.

// 생성 패턴 5개 : 객체를 만들때 사용하는 패턴
/// Singleton, Abstract Factory, Factory Method, Builder, Prototype ( r->Clone())

// 구조 패턴 7개 : 
/// 간접층 4개(adapter, facade, bridge, proxy )
/// 재귀적 포함2개(composite, decorator)
/// flyweight

// 행위 패턴 11개 : 
///  template method, strategy, state   => 변하는 것의 분리
///  iterator, visitor				=> 복합객체의 내부구조에 상관없이... 열거/연산
///  command, memento				=> 저장과 복구
///  observer, chain  of responsibility => 통보...전달..
///  mediator(M:N => 1:N), 
///  interpreter  (컴파일러의 파서등을 만들때 사용)

/// 장점 : 많은 오픈소스 라이브러리 및 언어 들이 "디자인패턴"을 활용해서 만들어 졌다
/// 단점 : 1990년대에 정리되었기 때문에 각 언어별 다양한 최신 기술이 없다...
///        C++의 경우 "C++IDioms" 참고..





