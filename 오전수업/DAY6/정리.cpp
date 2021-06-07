// 핵심 1. 공통성과 가변성의 분리
/// A. 변하는 것을 가상함수로    => "template method"
/// B. 변하는 것을 다른 클래스로 => "strategy"


// 핵심 2. A는 B뿐 아니라 A 자신도 포함할수 있다.- 재귀적 포함
//      => A, B는 공통의 기반클래스 필요
//      왜 재귀적 포함을 사용하는가 ???

/// A. "Composite" : 복합객체를 만들기 위해	
/// B. "Decorator" : 실행시간에 동적으로 객체에 기능을 추가하려고 =>


// 핵심 3. 간접층의 도입
/// A. Adapter : 사용자 ----------> stack ---------------> list .. 인터페이스의 변경

/// B. facade : 사용자 ----------> TCPServer -----------> IPAddress,Socket등 .. 사용하기 위한
///																		포괄적 인터페이스
/// C. Bridge : 사용자 ----------> MP3 -----------------> IMP3.. 상호 독립적인 update

/// D. Proxy : 사용자 ----------> Calc ----------------> IPC서버.. 대신하는 범용적 용도의객체를 만들어서
///												다양한 기능 추가(cache 등의기능)








