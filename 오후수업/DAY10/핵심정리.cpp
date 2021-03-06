// 핵심 정리
// 1. 공통성과 가변성의 분리
//    변하지 않은 코드에서 변하는 코드를 분리

/// A. 변하는 것을 가상함수로 => 파생 클래스를 만들어서 가상함수를 재정의 하라는 의도..
///     1. template method
///     2. factory method

/// B. 변하는 것을 다른 클래스로 - 실행시간에 교체도 가능하다.
///     1. strategy : 객체가 사용하는 알고리즘이 여러가지가 있다면 알고리즘을 캡슐화 해서 교체가능하게
///     2. state    : 객체에 상태에 따라 동작(멤버함수)가 변경. 객체가 다른 클래스를 사용하는 것처럼 보인다.
///     3. builder  : 복잡한 객체를 생성할때, 동일한 공정을 사용하지만, 각공정의 표현이 다를 때


// 2. 재귀적 포함을 사용하는 디자인 패턴
//    A가 B를 포함하지만 A 자신도 포함 => 공통의 기반 클래스

///    1. composite : 재귀적 포함을 사용해서 복합객체 만들기 ( PopupMenu/MenuItem, Folder/File, MacroCommand)
///    2. decorator : 재귀적 포함을 사용해서 객체에 기능추가 ( 파일 쓰기 => "암호화" 파일 쓰기 )


// 3. 간접층의 원리

///   1. adapter : 인터페이스의 변경(stack 예제, TextView), 객체어답터, 클래스 어답터
///   2. facade  : 하위시스템의 복잡함을 단순화 하는 상위 시스템(TCPServer)
///   3. bridge  : 추상과 구현을 분리해서 독립적 update 를 가능하게 (MP3/IMP3, PIMPL(PointImpl 예제))
///   4. proxy   : 대행자를 만들어서 다양한 기능 추가(CalcProxy), 참조계수, 동적모듈


// 4. 복합객체

/// 1. iterator  : 복합객체의 내부구조에 상관없이 동일한 방법으로 열거 ( 인터페이스기반, STL 방식)
/// 2. visitor   : 복합객체의 내부구조에 상관없이 동일한 방법으로 연산

// 5. ETC

/// 1. command : 명령을 캡슐화 해서 저장/복구가 가능하게 한다. (Undo/Redo) 동작 저장
/// 2. memento : 객체의 상태를 저장/복구 가능하게 한다.  ( token = g.SaveState(),  g.RestoreState())

/// 3. observer : 객체를 1 : N 의 구조로 구성해서, 객체의 변화를 연결된 모든 객체에게 전달한다.
/// 4. chain of responsibility : 발생된 이벤트를 처리할 객체를 만날때 까지 고리에 따라 전달

/// 5. flyweight : 속성이 동일한 객체는 공유 하자(Image 예제)


// GoF's 디자인 패턴 책에는 23개의 패턴을 3가지로 분류 합니다.
// ( Gangs Of Four )

// 생성 패턴 5가지 : 객체를 만들때 사용하는 패턴
/// singleton, abstract factory, factory method, builder, prototype (  r->Clone() )


// 구조 패턴 7가지 :
///  간접층을 만드는 패턴 4가지(adapter, facade, bridge, proxy)
///  재귀적포함 2가지(composite, decorator)
///  flyweight


// 행위 패턴 11가지 : 
///		변하는 것의 분리 : template method, state, strategy
///     열거 방문 : iterator, visitor
///     저장/복구 : command, memento
///     통보/전달 : observer, chain of responsibility
///     기타      : mediator
///      interpretor(컴파일러 같은 파서 만들때 )

// 디자인 패턴을 알면..

// 장점 : 많은 라이브러리가 디자인 패턴기반으로 설계 되었다. 통찰력을 얻을수 있다.
//        C#, swift, java 등의 언어도 디자인 패턴을 고려해서 설계

// 단점 : 좀 오래되었다... 새로운 문법이 적용된 설계기술이 정리될 필요 있다.
//        1990년대 나온 내용.

// C++ Idioms, 
