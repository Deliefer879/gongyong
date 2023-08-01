C++
===

### [참고서적  :전문가를 위한 C++](https://m.hanbit.co.kr/store/books/book_view.html?p_code=B3215427289)  
  

<details>
<summary>  목차  </summary>
<div markdown="1">       

> 1. Part1 : 전문가를 향한 C++ 첫 걸음 (필기X)
> > 1. C++와 표준 라이브러리 초단기 속성 코스
> > 2. 스트링과 스트링 뷰 다루기
> > 3. 코딩 스타일
> 2. [Part2 : 전문가답게 C++ 소프트웨어 디자인하기](#part2)
> > 4. 전문가다운 C++ 프로그램 디자인
> > 5. 객체지향 디자인
> > 6. 재사용을 고려한 디자인
> 3. [Part3 : 전문가답게 C++ 코딩하기](#part3)
> > 7. 메모리 관리
> > 8. 클래스와 객체 숙달하기
> > 9. 클래스와 객체 마스터하기
> > 10. 상속 활용하기
> > 11. C++의 까다롭고 유별난 부분
> > 12. 템플릿으로 제네릭 코드 만들기
> > 13. C++ I/O 완전 분석
> > 14. 에러 처리하기
> > 15. C++ 연산자 오버로딩하기
> > 16. C++ 표준 라이브러리 둘러보기
> > 17. 컨테이너와 반복자 살펴보기
> > 18. 표준 라이브러리 알고리즘 마스터하기
> > 19. 스트링 현지화와 정규표현식
> > 20. 여러 가지 유틸리티 라이브러리
> 4. [Part4 : ](#part4)
> >  

</div>
</details>

***
# Part2
## 4. 전문가다운 C++ 프로그램 디자인 
</br>

### 4.1 프로그램 디자인의 정의  

프로그램 디자인이란 프로그램의 구현 계획을 정리한 것으로 문서 형태로 작성하며  
대부분 다음과 같이 크게 두 부분으로 구성

1. 프로그램을 구성하는 서브 시스템
- 인터페이스와 서브시스템 사이의 의존성, 시브시스템 사이의 데이터 흐름,   
  서브시스템에 대한 입출력, 기본 스레드 활용 모델
2. 서브시스템별 세부사항
- 클래스 구성, 클래스 계층도, 데이터 구조, 알고리즘, 개별 스레드 활용 모델, 에러 처리 방법  
  </br></br>

### 4.2 프로그램 디자인의 중요성  
코드를 작성하기 전에 공식적인 디자인 단계를 거치면 프로그램의 전반적인 구조를 제대로 구성할 수 있다.  
디자인 단계를 거치지 않으면 서브시스템 사이의 관계, 재사용 또는 공유 정보 가능성, 그리고 주어진 작업을  
처리하기 위한 가장 쉬운 방법 등을 놓치기 쉽다.  
</br></br>

### 4.3 C++에 적합한 디자인 방법(별 내용 없음)  
</br></br>

### 4.4 C++ 디자인에 관련된 두 가지 원칙  

1. 추상화  
어떤 종류의 대상들에 대해 그것이 가져야 할 핵심적인 특징들을 가지는 모델을 만드는 것으로  
내부 구현과 외부 인터페이스가 명확히 분리되어 있어 내부 구조를 모르더라도 사용에 지장이 없다.

2. 재사용  
기존 코드를 활용하는 것으로 cout로 화면에 출력하는 코드도 재사용한 것이다.  
화면에 데이터를 출력하는 코드를 직접 작성하지 않고, 기존의 cout를 사용  
C++에서는 코드를 범용적으로 만들 수 있도록 **템플릿**이라는 기능을 제공  
</br></br>

### 4.5 코드 재사용  
재사용할 코드를 만드는 형식
* 독립 함수 또는 클래스 : 자신 또는 동료가 작성한 코드는 대부분 이런 형태로 재사용
* 라이브러리 : 특정한 작업을 처리하는데 필요한 코드를 한데 묶은 것
* 프레임워크 : 디자인할 프로그램의 기반이 되는 코드를 모아둔 것
* > 프로그램은 라이브러리를 활용하고, 프레임워크에 맞게 작성한다.  
즉 라이브러리는 특정한 기능을 제공, 프레임워크는 프로그램의 디자인과 구조에 대한 토대를 제공.
* API : 특정한 기능을 수행하는 코드나 라이브러리에 대한 인터페이스
* > API와 라이브러리는 다른 것으로 라이브러리는 구현을 의미하고  
API는 라이브러리를 외부에 제공하기 위한 인터페이스

4장에서는 간결한 표현을 위해 재사용 가능한 코드를 모두 라이브러리라고 표현  
</br>

코드 재사용 전략  
재사용하려는 코드가 라이브러리든 프레임워크든 관계없이 공통적으로 고려할 사항이 몇 가지 있다.

<details>
<summary>  1. 기능과 제약사항 파악하기  </summary>
<div markdown="1">       

* 멀티스레드 프로그렘에서 사용해도 안전한지  
* 라이브러리를 사용하는 코드에 대해 특별히 컴파일러에 설정해야 할 사항이 있는지
* 초기화나 종료 시 반드시 수행할 작업이 있는지
* 의존하는 라이브러리가 있는지
* 클래스를 상속할 때 어떤 생성자를 호출해야 하고 어떤 가상 메서드를 오버라이드해야 하는지  
* 함수가 메모리 포인터를 리턴할 때 그 메모리를 해제하는 작업을 호출한 코드와 라이브러리 중 어느 쪽이  
책임져야 하는지 파악(라이브러리에서 처리시 메모리 해제 시점을 파악)
 * 라이브러리 호출할 때 어떤 에러 조건을 확인해야 하는지
 * 함수에서 리턴하는 값이나 레퍼런스
 * 함수에서 발생하는 익셉션

</div>
</details>

<details>
<summary>  2. 성능 파악하기  </summary>
<div markdown="1">       

* 보통 빅오 표기법을 사용해 성능을 표현
* 빅오 실행기간이 같더라도 실제 속도는 다를 수 있다.
* 입력 크기가 작은 경우 O(n^2)이 O(n log n)보다 더 나을 수 있다.  
그러므로 프로그램에서 다룰 입력 크기부터 가늠한 뒤 알고리즘을 선정
* 사용할 라이브러리 코드의 실행 빈도를 고려

</div>
</details>

<details>
<summary>  3. 플랫폼 제약사항 파악하기  </summary>
<div markdown="1">       
</div>
</details>

<details>
<summary>  4. 라이선스와 기술 지원 파악하기  </summary>
<div markdown="1">       
</div>
</details>

<details>
<summary>  5. 도움을 받을 수 있는 곳 파악하기  </summary>
<div markdown="1">       
</div>
</details>
</br>  

오픈소스 라이브러리 : 기능을 구현시 많은 도움이 됨(라이선스 문제가 있을 수 있음)  
C++ 표준 라이브러리 : 기능,성능,직교성 위주로 디자인한 것으로 활용시 얻을수 있는 효과가 상당함  
</br></br>

### 4.6 (SKIP)
</br></br>

### 4.7 요약
> 디자인 개념
> 1. 추상화
> > 인터페이스와 구현을 분리  
> > 디자인할 때 반드시 적용해야 함
> 2. 재사용
> > 라이브러리, 프레임워크등을 재사용뿐만 아니라 개념 및 디자인에 대한 재사용도 반드시 고려해야 한다.  
> > 코드는 최대한 재사용할 수 있게 만든다.

</br></br>

## 5. 객체지향 디자인  
</br>

### 5.1 절차형 사고방식
C언어와 같은 절차형 언어는 하나의 작업만 담당하는 프로시저라 부르는 작은 단위로 코드를 구성한다.  
* 프로시저 : 일종의 추상화 기법으로서 "이 프로그램이 무슨 일을 하는가?"라는 기본 질문을 바탕으로 발전된 개념이다.  

일정한 단계에 따라 진행하는 프로그램이라면 절차형 접근 방식이 적합  
하지만 대규모 애플리케이션에서는 여러 이벤트가 일정한 순서 없이 발생하고 사용자는 원하는 명령을 언제든지 수행 가능해야 함
</br></br>

### 5.2 객체지향 철학
절차형 접근 방식은 "이 프로그램이 무슨 일을 하는가?"라는 질문을 토대로 접근  
객체지향 접근 방식은 "현실세계의 어떤 대상을 모델링하는가?"
</br>  
객체지향 프로그래밍에서는 프로그램을 작업 단위가 아니라 물리적인 대상에 대한 모델 단위로 나눈다.  
 
1. 클레스  
어떤 대상의 유형을 정의하는 속성을 정리한 것으로  
객체란 어떤 클래스에 속하는 구체적인 인스턴스이다.  

2. 컴포넌트  
본질적으로 클래스와 같지만 클래스보다 작고 구체적이라는 점만 다르다.  
클래스를 여러 개의 작고 관리하기 쉬운 컴포넌트로 나누며, 이 나눈 컴포넌트 또한  
또 다른 컴포넌트를 가질 수 있다.  

3. 프로퍼티  
객체는 프로퍼티(속성)로 구분된다. 클레스 프로퍼티의 값은 그 클래스에 속한 모든 객체가 똑같이 가지지만  
객체 프로퍼티의 값은 그 클래스에 속한 객체마다 다를 수 있다.  
즉 프로퍼티는 객체의 특성을 표현한다. 다시말해 프로퍼티로 다른 객체와 구분할 수 있다.  

4. 동작  
객체가 하는 일 또는 그 객체로 할 수 있는 일을 표현한다.  
OOP에서는 어떤 기능을 수행하는 코드를 프로시저가 아닌 클래스 단위로 묶는다.  
여러가지 동작을 수행하는 클래스를 만들고 서로 상호작용하는 방식을 정의함으로써 데이터를 조작하는 코드를 횔씬 다양하게 제공할 수 있다.  
이러한 클래스의 동작은 클래스 메서드로 구현한다.  
</br></br>

### 5.3 객체 관점에서 바라보기
소프트웨어를 객체 관점으로 개발하는 데 적용할 수 있는 접근 방식은 크게 두 가지가 있다.  
1. 객체를 단순히 데이터와 기능을 잘 묶어주는 수단으로만 여기고 프로그램 전반에 걸쳐 사용해서 유지보수성을 높이는 것
2. OOP페러다임을 완벽히 적용해서 처음부터 모든 것을 객체로 표현하는 것

객체지향 시스템 설계시 주의해야 할 점
1. 과도한 객체화 : 객체로 만들 필요가 없는 사소한 것까지 객체로 만드는 경우
2. 지나친 일반화 : 객체를 과도하게 일반화하여 구체적인 대상을 표현하기 힘듬  
</br></br>

### 5.4 객체 관계
프로그래밍을 하다 보면 서로 다른 클래스가 공통적인 속성을 가지거나 최소 두 클래스가 서로 관련되는 경우가 있다.
객체지향 언어는 이런한 객체의 관계를 표현라기 위해 몇 가지 메커니즘을 지원하며
크게 has-a 관계와 is-a관계가 있다.

1. **has-a 관계(포함 관계,소유 관계, 집합 관계))**  
A는 B를 가진다 혹은 A에 B가 있다고 표현되는 객체 관계(한 객체가 다른 객체의 일부분)  

2. **is-a 관계(상속 관계)**  
is-a 관계는 OOP의 핵심 개념 중 하나인 상속에 대한 것으로 객체가 주로 계층 구조로 이루어졌다는 점을 모델링한 것이다.   
클래스를 is-a 관계로 엮으려면 공통 기능을 베이스 클래스(상위 클래스)로 묶어서 다른 클래스가 확장 수 있게 만들어야 한다.  
</br>
2-1 상속 기법  
파생 클래스를 부모 클래스와 구분하는 방법은 여러 가지가 있는데, 그중 한 개 혹은 여러 개의 기법을 조합해서 파생 클래스를 만든다.   
이러한 관계를 "A는 일종의 B로서..."라는 특성이 있다고 표현한다.  
   * 기능 추가 : 파생 클래스는 기능을 더 추가해서 부모 클래스를 보완한다.  
   * 기능 변경 : 파생 클래스는 부모 클래스가 가진 메서드를 변경하거나 무시(오버라이드)할 수 있다.  
   * 프로퍼티 추가 : 베이스 클래스를 상속한 파생 클래스에 새로운 프로퍼티를 추가할 수 있다.  
   * 프로퍼티 변경 : 메서드를 오버라이드하는 것처럼 프로퍼티도 오버라이드할 수 있다.(바람직하지 않을 때가 많다.)  
</br>

    2-2 다형성과 코드 재사용  
    다형성(폴리모피즘) : 프로퍼티와 메서드의 표준 셋으로 정해두면 그 형식에 맞는 객체라면 어느 것이든 서로 바꿔서 적용할 수 있다는 개념  

3. has-a관계와 is-a관계 구분하기  
두 관계를 구분하는 기준이 확실하지 않을 때가 많다. 따라서 구현할 클래스의 용도를 분석하고,  
기존 클래스에 있는 기능을 단순히 이용하기만 하는지 아니면 기존 기능을 변경하거나 새 기능을 추가하는지 확실히 파악해야 한다.  

4. not-a 관계  
두 클래스 관계 중 어느 것이 적합한지 따지기 전에 먼저 그런 관계가 설립할 수 있는지부터 살펴봐야 한다.  
객체지향 방식으로 계층을 구성하려면 억지로 관계를 형성하지 말고 기능 관점에서 관계를 표현해야 한다.  

5. 클래스 계층  
* 각 파생 클래스를 구현하다 보면 여러 가지 공통점을 발견할 수 있다. 이런 부분은 부모 클래스로 옮기는 게 좋다.  
* 현실세계에서 볼 수 있는 관계와 공통 기능 관점으로 분류한 관계 사이의 균형을 조절할 필요가 있다.
* 계층은 얼마든지 다르게 구성할 수 있다.
* 제대로 구현된 객체지향 계층은 다음과 같은 특성을 갖는다.
  * 기능적으로 의미 있는 관계에 따라 클래스를 구성한다.
  * 공통 기능을 베이스 클래스로 뽑아냈기 때문에 코드를 재사용하기 쉽다.
  * 부모가 추상 클래스가 아닌 이상 부모의 기능을 과도라게 오버라이딩하는 파생 클래스가 없다.  

6. 다중 상속  
다중 상속을 사용할 일이 많지 않지만 다중 상속이 꼭 필요한 경우가 있다. 하지만 단점도 존재한다.(가능하면 피하는 것이 좋음)  
    * 첫째. 다중 상속 관계는 시각적으로 표현하기 복잡하다.  
    * 둘째. 다중 상속 때문에 구조의 명확성이 깨질 수 있다.  
    * 셋째. 다중 상속은 구현하기 힘들다.  
</br>

7. 믹스인 클래스  
믹스인(첨가) 클래스 : is-a 관계를 완전히 구현하지 않고도 기능을 추가할 때 사용한다.(일종의 공유 관계)  
</br></br>

### 5.5 추상화  
1. 인터페이스와 구현  
추상화의 핵심은 인터페이스와 구현을 실질적으로 분리하는 데 있다.

2. 외부에 공개할 인터페이스 결정하기  
클래스를 디자인할 때는 다른 프로그래머가 이 클래스의 객체를 접근하는 방법도 정해야 한다.  
</br>
2-1 사용자 고려하기  
외부 인터페이스를 디자인할 때는 가장 먼저 사용할 사람을 분석  
2-2 용도 고려하기  
     * API  
       제품의 기능을 다양한 용도로 활용하거나 그 제품의 기능을 확장하기 위해 외부에 제공하는 인터페이스  
     * 유틸리티 클래스 또는 라이브러리  
       클래스나 라이브러리는 다양한 문맥에서 사용하기 때문에 활용 범위를 고려해서 디자인에 반영  
     * 서브시스템 인터페이스  
       핵심 목적을 분명히 하여 어떤 형태로 제공돼야 할지 결정
     * 컴포넌트 인터페이스  
       서브시스템, API보다 작은 인터페이스를 정의할 잉이 많다.  
       혼자서만 사용하더라도 남이 사용한다 생각하고 주 목적을 염두한체 이에 벗어난 기능을 외부에 노출하지 않도록 주의한다.  

    2-3. 미래 고려하기  
    인터페이스를 디자인할 때는 반드시 미래에 사용할 일도 고려해야 한다.  
</br>

3. 바람직한 추상화 디자인  
추상화가 잘된 인터페이스는 public 메서드로만 구성된다. 모든 코드는 구현 파일에 있고 클래스 정의 파일에는 없어야 한다.  
> 다시 말해 클래스 정의가 있는 인터페이스 파일은 변경할 일이 없어야 한다.  
> 클래스 하나만으로 추상화할 대는 각별히 주의한다. 작성하는 코드의 계층 구조가 너무 깊다면 주 인터페이스를 보조할 다른 클래스를 도입하는 것이 좋다.  
> 프로퍼티는 모두 메서드로 변환한다. 다시 말해 외부 코드에서 클래스에 직접 접근해서 데이터를 조작하면 안 된다.  
> 반복은 너무나도 중요해서 다시 한 번 강조한다. 자신이 디자인한 내용에 대해 반드시 조언을 수해서 수정사항을 반영하고,  
> 예전에 저지른 실수로부터 교훈을 얻는 과정을 끊임없이 반복한다.

</br>  

### 5.6 요약  
객체 사이의 관계를 잘 성정하면 단순히 코드의 재사용성이나 간결설에 도움이 될 뿐만 아니라 팀 단위로 협업하는 데 도움 된다.  
의미가 잘 반영된 객체 관계는 이해하기도 쉽고 유지보수하기도 편하다.
</br></br>  


## 6. 재사용을 고려한 디자인  
### 6.1 재사용 철학  
코드는 반드시 작성자뿐만 아니라 다른 프로그래머도 재사용할 수 있게 디자인해야 한다.  

  항상 다음과 같은 좌우명을 명심한다.
  > * 작성은 한 번, 사용은 여러 번  
  > * 무슨 수를 쓰더라도 코드 중복은 피한다.  
  > * 같은 일을 반복하지 않는다.

  이에 대한 근거
  > 1. 코드를 한 프로그램에서만 사용하는 경우는 극히 드물다.  
  > 2. 재사용을 고려해서 디자인하면 시간과 비용을 절약할 수 있다.  
  > 3. 작성한 코드는 반드시 팀 내 다른 프로그래머도 활용할 수 있어야 한다.  
  > 4. 재사용성이 낮으면 중복된 코드가 늘어난다.  
  > 5. 재사용하기 좋은 코드의 첫 번째 수혜자는 바로 작성자 자신이다.

</br>

### 6.2 코드를 재샤용할 수 있도록 디자인하는 방법  
  코드를 재사용할 수 있게 만드는 방법은 크게 두 가지가 있다.
   1. 용도나 분야가 달라도 충분히 사용할 수 있도록 범용성을 갖춰야 한다.
   2. 재사용 가능한 코드는 사용하기 쉽게 만들어야 한다.

  코드를 클라이언트에게 전달하는 방식도 중요하다. 코드의 전달 방식에 따라 이를 작성하는 데 적용되는 제약사항도 달라진다.  
    
  > 재사용할 수 있는 코드를 디자인하는 과정은 크게 두 가지로 나뉜다.
  > * 코드의 구조를 잘 구성한다.
  > * 작성한 라이브러리나 코드에서 제공하는 기능을 사용하는데 '진입점' 역할을 하는 인터페이스를 디자인 한다.

  </br>

  2-1 추상화 방법  
    핸들 : 인터페이스에서 리턴한 정보를 다른 곳에 전달하기 위해 클라이언트 코드에서 보관하는 정보로 불투명 클래스로 구현  
    불투명 클래스 : 내부 데이터 맴버를 직접 접근하지 못하게 하거나 게터나 세터로 간접 접근해야 하는 클래스


  2-2 재사용에 최적화된 코드 구조화  
  1. 서로 관련 없거나 논리적으로 구분되는 개념은 합치지 않기  
     컴포넌트는 반드시 한 작업만 처리하거나 여러 작업의 경우 서로 성격이 같은 것들만 처리하도록 한다.  
    즉 응집도를 높이는 데 주력한다. 이를 단일 책임성 원칙이라고도 부른다.  
    
      * 프로그램을 서브시스템 단위로 논리적으로 나누기  
        서브시스템을 디자인할 때 반드시 독립적으로 재사용할 수 있는 컴포넌트로 만든다. 즉 결합도를 낮게 만든다.
          
      * 클래스 계층을 사용해서 논리적으로 나누기  
            프로그램을 논리적으로 나눌 때 서브시스템 관점뿐만 아니라 클래스 관점에서도 서로 관련 없는 개념이 한데 엮이지 않도록 주의한다.  
            마찬가지로 서로 관련 없는 개념도 하나로 합치지 않는다. **즉 전체 디자인 관점에서 응집도를 높인다.**  
          
      * 집합 관계를 사용해서 논리적으로 나누기  
            집합 관계(has-a)란 객체가 제공하는 기능의 일부분을 수행하는 객체를 따로 두는 것이다.  
          
      * 사용자 인터페이스에 대한 종속성 제거하기  
            데어터 관리 라이브러리를 만들 때는 데이터 조작 부분과 사용자 인터페이스 부분을 분리해야 한다.  
            즉 이런 종류의 라이브러리는 특정한 사용자 인터페이스의 타입에 종속되면 안 된다.  
            데이터를 저장하는 부분과 그 데이터를 시각적으로 표현하는 부분을 분리하는 데 적용하기 좋은 패턴에는 대표적으로 MVC패턴이 있다.  
</br>

  2. 제네릭 데이터 구조와 알고리즘을 템플릿으로 구현하기  
    C++에서 제공하는 템플릿을 이용하면 제네릭 구조체를 타입 또는 클래스 형태로 생성 가능  
    
       * 템플릿이 다른 제네릭 프로그래밍 테크닉보다 나은 이유  
      C,C++에서는 템플릿이 아니라 void* 포인터를 사용하여 제네릭 데이터 구조를 생성 시 void*로 캐스팅해서 모든 대상을 저장 할 수도 있음  
      하지만 이 방식은 타입 세이프하지 않다는 단점이 있고  
      또 다른 방법으로는 java와 같이 데이터 구조를 특정한 클래스에 맞게 정의하여 다형성을 이용하는 것이다.  
      하지만 이 방식 또한 타입에 안전하지 않고 원래 캐스팅했던 타입을 알고 있어야 한다.

       * 템플릿의 단점  
      템플릿은 문법이 복잡하며  
      동형(동종) 데이터 구조만 지원한다.  

       * 템플릿과 상속  
      동일한 기능을 다양한 타입에 제공할 때 : 템플릿  
      구체적인 타입마다 동작을 다르게 제공할 때 : 상속  
      
  3. 적절한 검사 기능과 안전장치 제공하기  
       안전한 코드를 작성하기 위한 두 가지 스타일  
       1. 계약에 따른 디자인   
          표준 라이브러리에서 흔히 사용하는 방식으로 함수나 클래스에 대한 문서는 클라이언트 코드에서 해야 할 일과   
          이 클래스나 함수가 제공할 것을 명시한 일종의 계약서와 같다.  
          계약 디자인 방식은 사전 조건, 사후 조건, 불변 조건이라는 세 가지 관점에서 바라본다.  
          * 사전(선행) 조건 : 함수나 메서드 호출 전 클라이언트 코드에서 만족해야하는 조건  
          * 사후(후행) 조건 : 함수나 메서드의 실행이 끝날 때 반드시 만족해야 할 조건  
          * 불변 조건 : 함수나 메서드의 전체 실행 과정에서 항상 만족해야 할 조건
       2. 함수나 클래스를 최대한 안전하게 디자인  
          사용하는 코드에서 에러 검사를 수행  
</br>

  4. 확장성을 고려한 디자인  
       클래스는 다른 클래스가 상속해서 확장하는 데는 개방적이면서, 구현을 수정하는 데는 폐쇄적인 방식으로 동작을 확장할 수 있게 디자인해야 한다.  
       이러한 원칙을 **개방/폐쇄 원칙**이라 부른다. 
   </br>  


  2-3 사용성 높은 인터페이스 디자인  

  1. 인터페이스를 사용하기 쉽게 디자인하기    
        사용하기 쉬운 인터페이스를 디자인하기 위한 네 가지 원칙
        * 익숙한 방식 따르기  
            C++ 프로그래머에게 익숙한 표준 이터페이스에 따라 디자인한다.  
    
          * 필요한 기능 빼먹지 않기  
            1 클라이언트가 필요로 하는 동작을 모두 인터페이스에 추가한다.  
            2 인터페이스에 최대한 많은 기능을 구현한다.  

          * 군더더기 없는 인터페이스 제공하기  
            쓸모없는 기능은 인터페이스에서 빼는 것이 좋다.   
            꼭 필요한 기능만 포함하고 필요없거나 생산성을 떨어뜨리는 기능은 과괌히 뺀다.

          * 문서와 주석 제공하기  
            제공하는 라이브러리나 코드를 다른 프로그래머가 사용할 제품이라 생각하여 사용법을 설명하는 문서를 제공한다.  
            문서를 제공하는 방법은 두 가지 방식이 있다.  
                1 인터페이스 코드 안에 주석을 첨부  
                2 별도의 문서를 제공(유닉스-멘페이지, 윈도우-IDE의 도움을 받아 제공)  
      
            주석이든 별도 문서든 라이브러리에 대한 문서를 작성할 때는 **구현이 아닌 동작에 초점을 맞춰 설명해야 한다.**

  2. 범용 인터페이스 디자인  
       * 하나의 기능을 다양한 방식으로 실행하게 만들기
       * 커스터 마이즈 지원하기  
         
  3. 범용성과 사용성의 조화  
       * 여러 가지 인터페이스 제공하기  
         기능을 충분히 제공하는 동시에 인터페이스의 복잡도를 낮추려면 인터페이스를 다양하게 제공하면 된다.  
         이를 **인터페이스 분리 원칙**이라 부른다.    
       * 자주 사용하는 기능 쉽게 만들기  
         범용 인터페이스 안에서도 자주 사용하는 기능은 쉽게 쓰도록 만들고, 고급 기능에 대한 옵션도 제공한다.  

  </br>  
  
  2-4 솔리드 원칙  
    객체지향 디자인의 기본 원칙을 기억하기 쉽도록 흔히 SOLID란 약어로 표현한다.  

  |솔리드 원칙|설명|  
  |:---|:---|  
  |S|SRP(Single Responsibility Principle)-단일 책임성 원칙 </br> 컴포넌트마다 하나의 잘 정의된 책임을 가지며 관련 없는 기능을 합치지 않는다.|
  |O|OCP(Open/Closed Principle)-개방/폐쇄 원칙 </br> 클래스는 (상속을 통해) 확장에는 개방적이고(열려 있고), 수정에는 폐쇄적이어야(닫혀 있어야) 한다.|
  |L|LSP(Liskov Subsititution Principle)-리스코프 치환 원칙 </br> 어떤 객체의 자리를 그 객체의 서브타입 인스턴스를 치환할 수 있어야 한다.|
  |I|ISP(Interface Segregation Principle)-인터페이스 분리 원칙 </br> 인터페이스는 깔끔하고 간결해야 한다. 거대한 범용 인터페이스보다는 </br>작지만 한가지 책무라도 잘 정의된 인터페이스를 여러 개로 구성하는 것이 낫다.|
  |D|DIP(Dependency Inversion Principle)-의존성 뒤집기/역전 원칙 </br> 인터페이스로 의존 관계를 역전시킨다. </br> 의존성 주입은 의존성 역전 원칙을 구현하기 윈한 방법 중 하나이다.| 
</br>  

### 6.3 요약  
  * 재사용 철학 : 작성은 한 번, 사용은 여러 번
  * 코드를 재사용할 수 있게 작성하려면 범용성과 사용성을 모두 갖춰야 한다.  
    또한 재사용할 수 있게 디자인하려면 추상화를 적용하고, 구조를 적절히 구성하고, 인터페이스도 잘 정의한다.  
  * 코드 구조화에 대한 4가지 팁
    * 서로 관련 없거나 논리적으로 구분디는 개념은 합치지 않는다.
    * 제네릭 데이터 구조나 알고리즘은 템플릿을 이용해서 만든다.
    * 오류 검사와 안전장치를 적절히 제공한다
    * 확장성을 지원하도록 디자인한다.
  * 인터페이스 디자인에 대한 여섯 가지 원칙
    * 흔히 사용하는 방식을 따르고
    * 필요한 기능을 빠뜨리지 않고
    * 군더더기 없는 인터페이스를 제공하고
    * 문서와 주석을 제공하고
    * 한 기능을 다양하게 사용할 수 있도록 제공하고
    * 커스터마이즈를 지원해야 한다.
  * 서로 충돌하기 쉬운 범용성과 사용성을 잘 조합하기 위한 두 가지 팁
    * 다양한 인터페이스를 제공
    * 자주 사용하는 기능은 쉽게
  * SOLID 원칙  
  
  </br></br>  

***
# Part3  

## 7. 메모리 관리

### 7.1 동적 메모리 다루기  

1-1 메모리의 작동 과정 살펴보기(skip)

1-2 메모리 할당과 해제  
  1. new와 delete 사용법  
      new의 리턴값을 무시하거나 그 포인터를 담았던 변수가 스코프를 벗어나면 할당했던 메모리에 **접근할 수 없다**.  
      이를 **메모리 누수**라 부른다. new로 메모리를 할당할 때 스마트 포인터가 아니라면 반드시 delete로 해제한다.

  2. malloc()
     C++도 여전히 malloc()을 지원하지만 new를 사용하는 것이 바람직함
  
  3. 메모리 할당에 실패한 경우  
     메모리가 부족한 경우 new가 실패하는 경우가 있다. 이 경우 예외 처리를 하거나 nothrow버전을 사용하면 프로그램이 종료되지 않는다.  
     nothrow버전은 실패시 nullptr을 리턴하기 때문에 컴파일에는 문제가 없기때문에 버그 발견이 힘들어진다. 때문에 표준 버전의 new가 바람직하다.

1-3 배열  
  1. 기본 타입 배열  
     프로그램에서 배열에 대한 메모리를 할당하면 실제 메모리에서도 연속된 공간을 할당한다.   
  2. 객체 배열  
     객체에 대한 배역도 기본 타입 배열과 비슷하다.
  3. 배열 삭제하기  
     객체 배열은 delete[]를 사용하며 포인터 배열은 일일히 delete해준다.
  4. 다차원 배열
     * 다차원 스택 배열  
       실제로 이차원 배열은 내부적으로 일차원 배열처럼 표현된다.  
     * 다차원 힙 배열    
       차원 수를 실행 시간에 결정하고 싶다면 힙 배열로 생성한다.  
       다차원 힙 배열은 스택 배열처럼 자동으로 하위 배열을 할당해주지 못한다.  
       그래서 사용자가 직접 할당해주어야 하고 해제할때도 직접 일일이 해제해야 한다.

1-4 포인터 다루기  
  1. 포인터의 작동 방식  
     포인터는 메모리의 한 저점을 가리키는 숫자에 불과하다.
  2. 포인터에 대한 타입 캐스팅  
     포인터의 타입은 C스타일 캐스팅을 이용해서 얼마든지 바꿀 수 있다.  
     정적 캐스팅을 사용하면 관련 없는 데이터 타입으로 포인터를 캐스팅하면 컴파일 에러가 발생한다.  
     상속 관계에 있는 대상끼리 캐스팅할 때는 동적 캐스팅을 사용하는 것이 더 안전하다.  

</br>  

### 7.2 배열과 포인터의 두 얼굴

2-1 배열 = 포인터  
스택 배열을 포인터로 접근이 가능하다. 이를 이용해서 함수의 매개변수로 배열을 전달 시 배열의 포인터를 전달할 수 있다. 

2-2 포인터가 모두 배열은 아니다!  
</br>

### 7.3 로우레벨 메모리 연산  
3-1 포인터 연산  
포인터를 int로 선언하고 그 값을 1만큼 증가시키면 포인터는 메모리에서 한 바이트가 아닌 int크기 만큼 이동  

3-2 커스텀 메모리 관리  
메모리를 직접 다룰 때 잭체 크기를 사전에 알고 잇다면 객체 크기를 관리할 공간을 줄일 수 있다.  
크기가 작은 객체가 아주 많으면 이렇게 절약한 효과가 상당하다.  

3-3 가비지 컬랙션  
C++은 기본적으로 가비지 컬랙션을 제공하지 않는다. 하지만 C++에서 가비지 컬랙션을 구현할 수는 있다.  
가비지 컬랙션을 구현하는 기법 주엥 표시 후 쓸기란 알고리즘이 있다.  
 이 방식에 따르면 가비지 컬랙터가 프로그램에 있는 모든 포인터를 주기적으로 검사한 뒤  
 여기서 참조하는 메모리를 계속 사용하고 있는지 여부를 표시한다. 한 주기가 끝날 시점에  
 아무런 표시가 되지 않은 메모리는 더 이상 사용하지 않는 것으로 간주하고 해제한다.  

 가비지 컬랙션 구현  
 1. 모든 포인터를 쉽게 탐색하도록 포인터를 가비지 컬렉터에 리스트 형태로 등록한다.
 2. 가비지 컬렉터가 객체의 사용 상태를 표시할 수 있도록 모든 객체가 GarbageCollectible과  
    같은 믹스인 클래스를 상속하게 만든다.
 3. 객체에 동시에 접근하지 못하도록 가비지 컬렉터가 작동하는 동안 포인터를 변경할 수 없게 한다.

가비지 컬랙터의 단점
1. 가비지 컬렉터가 작동하는 동안 프로그램이 멈출 수 있다.
2. 가비지 컬렉터가 있으면 소멸자가 비결정적으로 호출된다. 객체는 가비지 컬렉터에서 처리하기 전에는 제거되지 않기 때문에  
   객체는 가비지 컬렉터에서 처리하기 전에는 제거되지 않기 때문에 객체가 스코프를 벗어나더라도 소멸자가 즉시 실행되지 않는다.  
   즉, 소멸자에서 처리하는 리소스 정리 작업(파일을 닫거나 잠금을 헤제하는 등과 같은)은 일정한 시점에 이르기 전에는 실행되지 않는데,  
   얼마나 기다려야 할지 미리 알 수 없다.

   가비지 컬렉션 메커니즘을 구현하기란 상당히 어렵다. 잘못 구현하기도 쉽고 에러도 많이 발생 할 것이고, 무엇보다도 속도가 느릴 가능성이 높다.  
   (쓰고 싶으면 라이브러리 사용)

3-4 객체 풀  
객체 풀은 타입이 같은 여러 개의 객체를 지속적으로 사용해야 하지만 매번 객체를 생성하면 오버헤드가 상당히 커지는 상황에 적용하기 좋다. (25장)  

### 7.4 스마트 포인터  
스마트 포인터의 종류는 다양하다. 가장 간단한 것은 리소스에 대한 고유 소유권을 받는 것이다. 그래서 스마트 포인터가 스코프를 벗어나거나 리셋되면 참조하던  
리소스를 해제한다. 표준 라이브러리에서 제공하는 std::unique_ptr가 바로 이러한 고유(단독) 소유권 방식을 지원한다.(주로 사용)

앨리어싱 : 어떤 포인터의 복사본을 여러 객체나 코드에서 갖고 있는 경우  

모든 리소스를 제대로 해제하려면 리소스를 마지막으로 사용한 포인터가 해제해야 한다.  
그러나 코드의 어느 지점에서 그 리소스를 마지막으로 사용하는지 알기 힘들 때가 많다. 그래서 리소스의 소유자를 추적하도록 **레퍼런스 카운팅(참조 횟수 계산 방식)** 을  
구현한 스마트 포인터도 있다. 표준 라이브러리에서 제공하는 std::shared_ptr가 바로 이러한 레퍼런스 카운팅을 이용하여 공유 소유권 방식을 지원한다.  

4-1 unique_ptr  
동적으로 할당한 리소스는 항상 unique_ptr와 인스턴스에 저장하는 것이 바람직하다.  

4-2 shared_ptr

4-3 weak_ptr
shared_ptr가 가리키는 리소스의 레퍼런스를 관리하는 데 사용

4-4 이동 의미론  
스마트 포인터를 리턴하는 과정을 굉장히 효율적으로 처리 가능(9장에서 자세히)

4-5 enable_shared_from_this  
객체의 메서드에서 shared_ptr이나 weak_ptr를 안전하게 리턴가능

### 7.5 흔히 발생하는 메모리 문제  
5-1 스트링 과소 할당 문제  
C 스타일 스트링에서 가장 흔히 발생하는 문제는 **과소 할당**이다.  
 이 문제는 주로 프로그래머가 스트링의 끝을 나타내는 널문자('\0') 가 들어갈 공간을 빼먹고 공간을 할당할때 발생한다.  
 또한 프로그래머가 스트링의 최대 크기를 특정한 값으로 미리 정해둘 때도 발생한다.

 과소 할당 문제 해결법  
 1. C++ 스타일 스트링을 사용한다. 그러면 스트링을 연결하는 작업에 필요한 메모리를 알아서 관리해준다.
 2. 버피를 전역 변수나 스택(로컬) 변수로 만들지 말고 힙 공간에 할당한다. 공간이 부족하면 현재 스트링을 저장하는 대 부족한 만큼만 추가로 할당하고, 원본 버퍼를 새 버퍼로 복사한 뒤, 스트링을 연결하고 나서 원본 버퍼를 삭제한다.
 3. 최대 문자 수('\0')를 입력받아서 그 길이를 넘어서 부분은 리턴하지 않고, 현재 버퍼에 남은 공간과 현재 위치를 항상 추적한다.

5-2 메모리 경계 침범  
버퍼 오버플로 에러 : 메모리에서 중요한 영역까지 덮어써져서 프로그램이 종료되는 에러  

5-3 메모리 누수  
new에 대응되는 delete를 빠짐없이 작성하더라도 누수 현상이 발생하는 경우가 있다.  
이를 방지하기 위해서는 최대한 스마트 포인터를 적용하는 것이 바람직하다.
1. 비주얼 C++을 이용한 췬도우 애플리케이션의 메모리 누수 탐지 및 수정 방법  
   마이크로소프트 비주얼 C++을 사용하고 있다면 라이브러리에서 제공하는 메모리 누수 감지 기능을 활용할 수 있다.

2. 밸그라인드를 이용한 리눅스 애플리케이션의 메모리 누수 탐지 및 해결 방법  
   벨그라인드 : 리눅스용 오픈소스 도구, 할당된 객체를 헤제하지 않는 지점을 줄 단위로 정확히 찾아준다.  

5-4 중복 삭제와 잘못된 포인터  
delete로 포인터에 할당된 메모리를 해제하면 그 메모리를 프로그램의 다른 부분에서 사용할 수 있다. 하지만 그 포인터를 계속 쓰는 것을 막을 수는 없다.  
이를 **댕글링 포인터**라 부른다. 이때 중복 삭제하면 문제가 발생한다. 한 포인터에 delete를 두 번 적용하면 이미 다른 객체를 할당한 메모리를 해제해버리기 때문이다.


### 7.6 요약  
동적 메모리에 관련된 문제를 방지하기 위한 두 가지 사항을 명심한다.
1. 포인터의 내부 작동 방식을 이해한다.
2. 동적 메모리 관련 문제가 발생하지 않도록 가능하면 C++의 string 클래스, vector컨테이너, 스마트 포인터처럼 메모리를 자동으로 관리하는 객체를 사용한다.

* 이 장에서 반드시 기억할 사항 : 기존 C 스타일 구문이나 함수를 최대한 피하고 안전한 C++구문을 사용한다.

</br>

***

## 8. 클래스와 객체 숙달하기
### 8.1 스프레드시트 예제  
스프레드시트 : 셀(cell)이란 단위로 구성된 2차원 격자   
</br>  

### 8.2 클래스 작성 방법  
클래스를 작성하려면 그 크랠스의 모든 객체에 적용할 동작(메서드)과 각 객체마다 가질 속성(데이터 맴버)을 지정한다.

2-1 클래스 정의  
1. 클래스 맴버  
   클래스는 여러 개의 맴버를 가질 수 있다. 맴버는 메서드, 생성자, 소멸자와 같은 함수(맴버 함수)일 수도 있고, 열거형, 타입 앨리어스, 중첩 클래스와  
   같은 변수(맴버 변수)일 수도 있다. 맴버 변수를 데이터 맴버라고도 부른다.

2. 접근 제어  
   클래스의 각 맴버는 세 가지 **접근 (제어) 제한자/지정자**인 public,protected,private 

  |접근자|설명|용도|  
  |:---|:---|:---|
  |public|객체의 public맴버 함수나 데이터 맴버는 어디에서나</br>접근할 수 있다.|클라이언트가 사용할 동작(메서드)</br>private 또는 protected 데이터 맴버에 대한 접근 메서드(게터와 세터)
  |protected|protected 맴버 함수나 데이터 맴버는 같은 클래스로 된 객체의 맴버 함수로 접근할 수 있다.</br>또한 파생 클래스의 맴버 함수는 베이스 클래스의 protected 맴버에 접근할 수 있다.|외부 클라이언트가 사용하면 안 되는 헬퍼 메서드에 적용한다.
  |private|private맴버 함수나 데이터 맴버는 같은 클래스의 맴버 함수로만 접근할 수 있다.</br> 파생 클래스의 맴버 함수는 베이스 클래스의 private 맴버에 접근할 수 없다.|기본적으로 모두 private로 지정한다. 특히 데이터 맴버라면 반드시 private로 지정한다.</br> 파생 클래스만 게터나 세터에 접근하게 하려면 protected로 지정하고, 외부 클라이언트도 접근하게 하려면 public로 지정한다.

  3. 선언 순서  
     C++에서는 맴버와 접근 제한자를 선언하는 순서를 따로 정해두지 않았다.

  4. 클래스 내부의 맴버 이니셜라이저
     클래스를 정의할 때는 맴버 변수를 선언하는 동시에 초기화할 수 있다.

</br>  


2-2 메서드 정의 방법  
1. 데이터 멤버 접근 방법  
2. 다른 메서드 호출하기  
3. this 포인터  
   일반 메서드를 호출하면 항상 메서드가 속한 객체의 포인터인 this가 숨겨진 매게변수 형태로 전달된다. this 포인터로 해당 객체의 데이터 맴버나 메서드에 접근할 수 있으며, 다른 메서드나 함수에 매개변수로 전달할 수도 있다.

</br>  

2-3 객체 사용법  
1. 스택에 생성한 객체  
    변수를 선언하는 방법과 같이 선언 후 사용
2. 힙에 생성한 객체  
   new를 사용해서 동적으로 생성

</br>

### 8.3 객체의 라이프 사이클  
객체의 라이프 사이클은 생성, 소멸(제거), 대입(할당)의 세 단계로 구성된다.

3-1 객체 생성  
스택 객체는 선언하는 시점에 생성되고, 스마트 포인터나 new, new[]를 사용할 때는 직접 공간을 할당해야 생성된다.  
 객체가 생성되면 그 안에 담긴 객체도 함께 생성된다.

1. 생성자 작성 방법  
   생성자 이름은 클래스 이름과 똑같이 지정한다. 생성자는 리턴값이 없으며 필요에 따라 매개변수를 받을 수 있다.  
   아무런 인수를 주지 않고 호출하는 생성자를 **디폴트 생성자**라 부른다.  
   
2. 생성자 사용법  
   객체는 생성자를 통해 생성되고 그 객체의 값을 초기화할 수 있다.
   * 스택 객체 생성자  
   * 힙 객체 생성자

3. 생성자 여러 개 제공하기
   오버로딩을 이용하여 인수의 개수나 타입이 다른 여러 개의 생성자를 제공할 수 있다.  
   생성자 안에서 다른 생성자를 호출할수는 있지만 의도한대로 실행되지 않는다. 단 같은 클래스에서 생성자끼리 호출할 수 있도록 위임 생성자를 사용하면 가능하다(P.341)

4. 디폴트 생성자  
   아무런 인수도 받지 않은 생성자로 **영인수(제로 인수) 생성자**라고도 부른다.
   * 디폴트 생성자가 필요한 경우  
     C++은 배열 생성 코드에서 각 생성자를 직접 호출하는 기능을 제공하지 않는다. 그래서 디폴트 생성자 없이 객체 배열 생성지 컴파일 에러가 발생
   * 디폴트 생성자 작성 방법(skip)  
   * 컴파일러에서 생성한 디폴트 생성자  
   * 명시적 디폴트 생성자          
   * 명시적으로 삭제된 생성자

5. 생성자 이니셜라이저  
   C++는 생성자에서 데이터 맴버를 초기화하기 위한 또 다른 방법인   
   **생성자 이니셜라이저(ctor 이니셜라이저 또는 맴버 이니셜라이저)** 를 제공한다.  
   몇가지 데이터 타입들은 반드시 생성자 이니셜라이저나 클래스 내부 생성자 구문으로 초기화 하여야 한다.  
   1. const 데이터 맴버
   2. 레퍼런스 데이터 맴버
   3. 디폴트 생성자가 정의되지 않은 객체 데이터 맴버 
   4. 디폴트 생성자가 없는 베이스 클래스  

* 주의사항 : 생성자 이니셜라이저는 클래스 정의에 선언된 순서대로 데이터 맴버를 초기화한다.  
 생성자 이니셜라이저에 나온 순서가 아니다.

6. 복제 생성자  
   * 복제 생성자가 호출되는 경우  
     C++에서 함수에 인수를 전달할 때 기본적으로 값으로 전달한다.  
     함수나 메서드에 객체를 전달하면 컴파일러는 그 객체의 복제 생성자를 호출하는 방식으로 초기화한다.  
     함수에서 객체를 값으로 리턴할 때도 복제 생성자가 호출된다.  
    
   * 복제 생성자 명시적으로 호출하기  

   * 레퍼런스로 객체 전달하기  
     함수나 매서드에 객체를 레퍼런스로 전달하면 복제 연산으로 인한 오버해드를 줄일 수 있다.  
     
   * 명시적으로 디폴트로 만든 복제 생성자와 명시적으로 삭제된 복제 생성자  
     컴파일러가 생성한 복제 생성자를 명시적으로 디폴트로 만들거나 삭제가능  
     (객체를 값으로 전달하지 않게 할 때 이렇게 설정) 
      
 7. 이니셜라이저 리스트 생성자  
    std::initializer_list<T>를 첫 번째 매개변수로 받고, 다른 매개변수는 없거나 디폴트값을 가진 매개변수를 추가로 받는 생성자    

 8. 위임 생성자  
    위임 생성자를 사용하면 같은 클래스의 다른 생성자를 생성자 안에서 호출할 수 있다.  
    하지만 직접 호출할 수는 없다. 반드시 생성자 이니셜라이저에서 호출해야 하며  
    맴버 이니셜라이저에 이것만 적는다.
  
 9. 컴파일러가 생성하는 생성자에 대한 정의  
    |직접 정의한 생성자|컴파일러가 만들어주는 생성자|
    |:---|:---|
    |없음|디폴트 생성자</br>복제 생성자|
    |디폴트 생성자만 정의한 경우|복제 생성자|
    |복제 생성자만 정의한 경우|없음|
    |한 개의 인수 또는 여러 개의</br>인수를 받는, 복제 생성자가</br>아닌 생성자만 정의한 경우|복제 생성자|
    |한 개의 인수 또는 여러 개의</br>인수를 받는, 목제 생성자가</br>아닌 생성자 또는 디폴트</br>생성자 하나만 정의한 경우|복제 생성자|
    

    * 또 다른 생성자로 이동 생성자가 있다. 이 생성자는 이동 의미론을 구현하는데 필요하다.


</br>  

3-2 객체 소멸  
객체가 제거되는 과정은 두 단계로 구성된다. 먼저 객체의 소멸자를 호출한 다음 할당받은 메모리를 반환한다.  
스택 객체는 현제 실행하던 함수, 메서드 또는 코드 블록이 끝날 때와 같이 스코프(유효 범위)를 벗어날 때 자동으로 삭제된다.  


</br>

3-3 객체에 대입하기  
C++은 클래스마다 대입을 수행하는 메서드인 대입 연산자를 따로 제공한다.  
  
  1. 대입 연산자 선언 방법
     대입 연산자는 복제 생성자처럼 원본 객체에 대한 const레퍼런스를 받은 때가 많다.  
     그런데 대입 연산자는 복제 연산자와 달리 객체에 대한 레퍼런스를 리턴한다.  
      그 이유는 여러 개의 대입 연산이 연달아 있을 수 있기 때문이다.

  2. 대입 연산자 정의 방법  
     대입연산자를 구현하는 방법은 복제 생성자와 비슷하지만 몇 가지 중요한 차이점이 있다.  
     첫째, 복제 생성자는 초기화할 때 단 한 번만 호출
     둘째, C++는 객체에 자기 자신을 대입할 수 있다.

  3. 명시적으로 디폴트로 만들거나 삭제한 대입 연산자  
     컴파일러가 자동으로 생성한 대입 연산자를 명시적으로 디폴트로 만들거나 삭제할 수 있다.

</br>

3-4 컴파일러가 만들어주는 복제 생성자와 복제 대입 연산자.  

</br>

3-5 복제와 대입 구분하기  
1. 리턴값이 객체인 경우  
   값을 리턴할 때 복제 생성자의 오버헤드가 크다면 **리턴값 최적화** 또는 **복제 생략**을 적용해 최적화하기도 한다.  
2. 복제 생성자와 객체 맴버  
   생성자에서 대입 연산자를 호출할 때와 복제 생성자를 호출할 때의 차이점  
   : 어떤 객체가 다른 객체를 담고 있다면 컴파일러에서 만들어준 복제 생성자는 객체에 담긴 객체의 복제 생성자를 재귀적으로 호출한다.

### 8.4 요약 (SKIP)

</br>

***

## 9 클래스와 객체 마스터하기  
### 9.1 friend  
C++은 클래스 안에서 다른 클래스의 맴버 함수 또는 비맴버 함수를 friend로 지정하면  
이 클래스의 protected나 private 데이터 맴버와 메서드에 접근할 수 있다.  
friend로 지정할 클래스, 메서드, 함수는 반드시 접근할 클래스 안에서 지정해야 한다.  
friend 키워드를 남용하면 캡슐화의 원칙이 깨지므로. 꼭 필요할 때만 사용한다.

### 9.2 객체에 동적 메모리 할당하기  
2-1 Spreadsheet 클래스(skip)
</br>
2-2 소멸자로 메모리 해제하기  
객체 안에서 동적으로 할당한 메모리는 그 객체의 소멸자에서 해제하는 것이 바람직하다.
소멸자는 기본적으로 noexcept(예외 발생 X)가 적용되며 예외 발생시 프로그램이 멈춘다.  

2-3 복제와 대입 처리하기  
int, double, 포인터와 같은 기본 타입에 대해서는 **비트 단위 복제, 얕은 복제** 또는 대입이 적용된다.
그런데 메모리를 동적으로 할당한 객체를 이렇게 처리하면 문제가 발생한다.  
2개의 포인터가 1개의 메모리 공간을 가르키고 있을 수도 있으며 댕글링 포인터가 될수도 있다.
1. Spreadsheet 복제 생성자  
2. Spreadsheet 대입 연산자
3. 대입과 값 전달 방식 금지

2-4 이동 의미론으로 이동 처리하기  
1. 우측값 레퍼런스  
   우측값에 대한 레퍼런스로 우측값이 임시 객체일 때 적용되는 개념으로 우측값 레퍼런스는 임시 객체에 대해 적용할 함수를 컴파일러가 선택하기 위한 용도로 사용한다.
   함수의 매개변수에 &&를 붙여서 우측값 레퍼런스로 만들 수 있다. 일반적으로 임시 객체는 const type&로 취급하지만 함수의 오버로딩 버전 중에서 우측값 레퍼런스를 사용하는 것이 있다면 그 버전으로 임시 객체를 처리한다.
   좌측값 : 변수처럼 이름과 주소를 가진 대상  
   우측값 : 리터럴, 임시 객체, 값처럼 좌측값이 아닌 모든 대상  
   
2. 이동 의미론 구현 방법
   이동 의미론은 우측값 레퍼런스로 구현한다. 클래스에 이동 의미론을 추가하려면 이동 생성자와 이동 대입 연산자를 구현해야 한다. 이때 이동 생성자와 이동 대입 연산자를 noexcept로 지정해서 두 메서드에서 익셉션이 절대로 발생하지 않는다고 컴파일러에 알려줘야 한다. 
   이동 의미론은 원본 객체를 삭제할 때만 유용
   
   **5의 규칙 : 클래스에 동적 할당 메모리를 사용하는 코드를 작성했다면 소멸자, 복제 생성자, 이동 생성자, 복제 대입 연산자, 이동 대입 연산자를 반드시 구현한다.**

   * 객체 데이터 맴버 이동하기  
   * swap()함수로 구현한 이동 생성자와 이동 대입 연산자 

3. Spreadsheet의 이동 연산자 테스트  
   
4. 이동 의미론으로 swap함수 구현하기  

2-5 영의 규칙  
앞에서 적은 5의 규칙에 최신 C++은 일명 0의 규칙이란 것도 추가했다.
이 규칙은 앞서 언급한 5가지 특수 맴버 함수를 구현할 필요가 없도록  클래스를 디자인해야 한다는 것이다.

### 9.3 메서드의 종류  
3-1 static 메서드  
메서드도 데이터 맴버처럼 특정 객체 단위가 아닌 클래스 단위로 적용되는 것이 있다. 이를 static 메서드라 부르며 데이터 맴버를 정의하는 단계에 함께 작성한다.

3-2 const 메서드  
const 객체란 값이 바뀌지 않는 객체를 말한다. const객체나 이에 대한 레퍼런스 또는 포인터를 사용할 때는 그 객체의 데이터 맴버를 절대로 변경하지 않는 메서드만 호출할 수 있다. 이처럼 어떤 메서드가 데이터 맴버를 변경하지 않는다고 보장하고 싶을 때 const 키워드를 붙인다.
1. mutable 데이터 맴버  
   때로는 의미상으로는 const인 메서드에서 객체의 데이터 맴버를 변경하는 경우가 있다. 이럴 떄는 변수를 mutable로 선언해서 컴파일러에 이 변수를  
   const메서드에서 변경할 수 있다고 알려주면 된다.  

3-3 메서드 오버로딩  
오버로딩 : 매개변수의 타입이나 개수만 다르게 지정해서 이름이 같은 함수나 메서드를 여러 개 정의할 수 있다.
1. const 기반 오버로딩  
   const를 기준으로 오버로딩할 수도 있다. 예를 들어 메서드를 두 개 정의할 때 이름과 매개변수는 같지만 하나는 const로 선언한다. 그러면 const 객체에서 이 메서드를 호출하면 const메서드가 실행되고, non-const 객체에서 호출하면 non-const 메서드가 실행된다.

2. 명시적으로 오버로딩 재거하기  
   오버로딩된 메서드를 명시적으로 삭제할 수 있다. 그러면 특정한 인수에 대해서는 메서드를 호출하지 못하게 된다.

3-4 인라인 메서드  
C++는 메서드를 별도의 코드 블록에 구현해서 호출하지 않고 메서드를 호출하는 부분에서 곧바로 구현 코드를 작성하는 방법도 제동한다. 이를 **인라이닝**이라 부르면 이렇게 구현한 메서드를 인라인 메서드라 부른다. 일반적으로 #define 메크로보다 인라인 메서드를 사용하는 것이 더 안전하다.
최신 컴파일러는 코드 블룻과 같은 몇 가지 기준에 따라 메서드나 함수를 인라인으로 처리할지 판단해서 큰 효과가 없다면 인라인으로 처리하지 않는다.
실제로는 간단한 메서드나 함수만 인라인으로 처리한다.

3-5 디폴트 인수  
이 기능을 이용하면 함수나 메서드의 프로토타입에 매개변수의 기본값을 지정할 수 있다.  
반드시 오른쪽 끝의 매개변수부터 시작해서 중간에 건너뛰지 않고 연속적으로 나열해야 한다.
디폴트 생성자가 있을때 모든 매개변수에 디폴트값이 지정된 생성자도 함께 작성하면 컴파일 에러가 발생한다.

### 9.4 데이터 맴버의 종류  
4-1 static 데이터 멤버  
클래스의 모든 객체마다 똑같은 변수를 가지는 것은 비효율적이거나 바람직하지 않을 수 있다.
데이터 멤버의 성격이 객체보다 클래스에 가깝다면 객체마다 그 맴버의 복사본을 가지지 않는 것이 좋다.  
static 데이터 멤버는 객체가 아닌 클래스에 속한다. 이는 전역 변수와 비슷하지만 자신이 속한 클래스 범위를 벗어날 수 없다.

1. 인라인 변수  
   C++17부터 static 데이터 맴버를 inline으로 선언할 수 있다. 그러면 소스 파일에 공간을 따로 할당하지 않아도 된다. 
2. 클래스 메서드에서 static 데이터 멤버 접근하기
   클래스 메서드 안에서는 static 데이터 멤버를 마치 일반 데이터 맴버인 것처럼 사용한다.  
3. 메서드 밖에서 static 데이터 멤버 접근하기  
   static 데이터 멤버에 대해서도 접근 제한자를 적용할 수 있다.
   static 데이터 맴버를 외부에서 접근하려면 static get/set 메서드를 사용하는 방식으로 구현한다.

4-2 const static 데이터 멤버  
특정 클래스에만 적용되는 상수(클래스 상수)를 정의할 때는 전역 상수로 선언하지 말고 반드시 static const(또는 const static) 데이터 멤버로 선언한다.
정수 및 열거 타입의 static const 데이터 멤버는 별도로 인라인 변수로 지정할 필요 없이 클래스 정의 코드에서 선언과 동시에 초기화할 수 있다.

4-3 레퍼런스 데이터 멤버  

4-4 const 레퍼런스 데이터 멤버  
일반 레퍼런스와 마찬가지로 레퍼런스 멤버도 const 객체를 가리킬 수 있다.  const 레퍼런스 데이터 멤버는 객체의 const 메서드만 호출할 수 있다.

### 9.5 중첩 클래스  
클래스 정의에 데이터 멤버와 메서드뿐만 아니라 중첩 클래스와 구조체, 타입 앨리어스, 열거 타입도 선언할 수 있다.
이들에 대한 스코프는 모두 그 클래스로 제한된다. 
중첩 클래스도 일반 클래스와 똑같은 접근 제어 규칙이 적용된다. 중첩 클래스를 private나 protected로 선언하면 중첩 클래스를 담고 있는 클래스 내에서만 접근할 수 있다.
중첩 클래스는 이를 감싸고 있는 클래스의 모든 protected와 priivate 멤버와 접근할 수 있는 반면 이를 감싸는 클래스는 중첩 클래스의 public 멤버만 접근할 수 있다.

### 9.6 클래스에 열거 타입 정의하기  
클래스 안에서 상수를 여러 개 정의할 때는 각각을 #define 문으로 작성하지 말고 열거 타입을 활용하는 것이 좋다.  

### 9.7 연산자 오버로딩  

### 9.8 안정적인 인터페이스 만들기  
8-1 인터페이스 클래스와 구현 클래스  
인터페이스를 보다 간결하게 구성하고 구현 세부사항을 모두 숨겨서 인터페이스를 안정적으로 유지하는 방법이 있다.
기본 원칙은 작성할 클래스마다 인터페이스 클래스와 구현 클래스를 따로 정의하는 것이다.
구현 클래스는 원칙을 적용하지 않을 때 흔히 작성하는 클래스를 말한다.
인터페이스 클래스는 구현 클래스와 똑같이 public 메서드를 제공하되 구현 클래스 객체에 대한 포인터를 갖는 데이터 맴버 하나만 정의한다.
이를 **핌플 이디엄(핌플 구문)** 또는 **브릿지 패턴** 이라 부른다. 인터페이스 클래스 메서드는 단순히 구현 클래스 객체에 있는 동일한 메서드를 호출하도록 구현한다. 

### 9.9 요약  
객체에서 동적 메모리를 사용하면 여러 가지 까다로운 문제가 발생한다.
메모리 복제, 이동, 해제를 제대로 처리하도록 소멸자, 복제 생성자, 복제 대입 연산자, 이동 생성자, 이동 대입 연산자를 구현해야 한다.
또한 대입과 값 전달이 발생하지 않도록 복제 생성자와 대입 연사자를 명시적으로 삭제(delete를 지정)
복제 후 맞 바꾸기 구문으로 복제 대입 연산자를 구현하는 방법과 0의 규칙

static, const, const 레퍼런스, mutable 맴버
static, inline, const 메서드와 메서드 오버로딩, 디폴트 인수, 중첩 클래스, friend 클래스, 함수, 메서드

연산자 오버로딩, 산술 및 비교 연산자를 전역 friend 함수 또는 클래스 메서드로 오버로딩

인터페이스 클래스와 구현 클래스를 분리함으로써 추상화를 극대화하는 방법

***

## 10. 상속 활용하기  

### 10.1 상속을 이용한 클래스 구현  
프로그래밍할 때 클래스를 수정하거나 다른 클래스를 바탕으로 새 클래스를 정의할 때 이러한 관계를 분명히 볼 수 있다.
커드에서 이런 관계를 다루는 방법 중 하나는 기존 클래스를 그대로 복사한 뒤 그 위에서 작업을 진행하는 것이다.  
그러면 원본과는 약간 다르게 원하는 형태로 수정하는 방식으로 새로운 클래스를 정의할 수 있다. 
하지만 이렇게 하면 OOP 프로그래머 입장에서 작업이 단조롭거나 성가신 일이 발생할 수 있는데 그 이유는 다음과 같다.

* 원본 클래스에서 버그를 수정한 코드가 새 클래스에 반영되지 않는다. 두 코드가 완전히 별개이기 때문이다.
* 컴파일러는 두 클래스의 관계를 모른다. 따라서 한쪽이 동일한 클래스를 변형한 것으로 취급하지 않기 때문에 다형성을 구현할 수 없다.
* 진정한 is-a 관계가 아니다. 새 클래스의 코드 중 상당 부분이 원본과 같아서 서로 비슷하긴 하지만 그렇다고 타입이 같은 것은 아니다.
* 간혹 원본 클래스의 소스 코드를 구할 수 없거나 컴파일된 바이너리 버전만 있어서 소스 코드를 직접 복사 할 수 없을 수도 있다.

1-1 클래스 확장하기  
C++에서 클래스를 정의할 때 컴파일러에 기존 클래스를 **상속, 파생, 확장** 한다고 선언할 수 있다.
이떄 원본 클래스를 **부모 클래스(베이스 클래스 or 슈퍼 클래스)** 라 부른다.
그러면 기존 클래스를 확장한 **자식 클래스(파생 클래스 or 서브 클래스)** 는 부모 클래스와 다른 부분만 구현하면 된다.

1. 클라이언트 입장에서 본 상속  
   다른 코드에서 볼 때 객체는 그 객체를 직접 정의한 클래스뿐만 아니라 그 클래스의 모든 베이스 클래스의 타입으로 취급한다.
   어떤 객체를 포인터나 레퍼런스로 가리킬 때 그 객체를 선언한 클래스의 객체뿐만 아니라 그 클래스의 파생 클래스 객체도 가리킬 수 있다.
   그러나 부모 클래스 포인터로 자식 클래스의 메서드를 호출할 수는 없다.

2. 파생 클래스 입장에서 본 상속  
   파생 클래스는 베이스 클래스에 선언된 public 및 protected 메서드나 데이터 멤버를 마치 자신의 클래스 안에서 정의한 것처럼 사용할 수 있다.
   
3. 상속 방지  
   C++에서 클래스를 정의할 때 final 키워드를 붙이면 다른 클래스가 이 클래스를 상속할 수 없다.  
   
1-2 메서드 오버라이딩  
베이스 클래스에 정의된 메서드의 동작은 변경할 일이 많은데, 이는 **메서드 오버라이딩**을 이용해 가능하다.
1. 메서드 오버라이딩과 virtual 속성  
   C++에서는 베이스 클래스에 virtual 키워드로 선언된 메서드만 파생 클래스에서 오버라이드 할 수 있다.
   모든 메서드를 virtual로 선언하면 오버라이드 과정에서 메서드가 제대로 작동할지 신경 쓸 필요가 없다. 하지만 성능이 좀 떨어진다.

2. 메서드 오버라이딩 문법  
   파생 클래스에서 베이스 클래스의 메서드를 오버라이드하려면 그 메서드를 베이스 클래스에 나온 것과 똑같이 선언하고 맨 뒤에 override 키워드를 붙인다. 그러고 나서 메서드 본문에 파생 클래스에서 구현하려는 방식으로 코드를 작성한다.

3. 클라이언트 관점에서 본 오버라이드한 메서드  
   파생 클래스에서 오버라이드한 메서드를 베이스 클래스 포인터나 레퍼런스로 참조할 때는 원해 상태를 그대로 유지한다.
   파생 클래스 객체를 베이스 클래스 타입으로 캐스팅할 때만 파생 클래스 고유의 정보가 사라진다.
   이렇게 파생 클래스의 데이터 멤버나 오버라이드된 메서드가 삭제되는 것을 **슬라이싱**이라 부른다.

4. override 키워드  
   베이스 클래스의 메서드를 오버라이드할 때는 항상 override 키워드를 붙인다.

5. virtual 메서드  
   virtual로 선언하지 않은 메서드를 오버라이드하면 몇 가지 미묘한 문제가 발생한다.
   
   * 오버라이드하지 않고 숨기기
     virtual로 선언하지 않은 메서드를 오버라이드하면 베이스 클래스 정의를 **숨겨버린다.**
     그래서 오버라이드한 메서드를 파생 클래스 문맥에서만 사용할 수 있게 된다.
   
   * virtual 메서드의 내부 작동 방식
     C++에서 클래스를 컴파일하면 그 클래스의 모든 메서드를 담은 바이너리 객체가 생성된다.
     그런데 컴파일러는 virtual로 성언되지 않은 메서드를 호출하는 부분을 컴파일 시간에 결정된 타입의 코드로 교체한다.
     이를 **정적 바인딩** 또는 **이른 바인딩**이라 부른다.
     메서드를 virtual로 선언하면 **vtable(가상 테이블)**이라 부르는 특수한 메모리 영역을 활용해서 가장 적합한 구현 코드를 호출한다.
     그래서 객체에 대해 메서드를 호출하면 vtable을 보고 그 시점에 적합한 버전의 메서드를 실행한다. 이를 **동적 바인딩** 또는 **늦은 바인딩**이라 부른다.

   * virtual 키워드가 필요한 이유
     virtual 키워드를 이용하여 vtable에 대한 오버헤드를 줄일 수 있다. 하지만 최신 CPU에서 발생하는 오버헤드가 나노초 단위로 미미하다.
     따라서 모든 메서드를, 특히 소멸자는 virtual로 선언하는 관례를 따르는 것이 바람직하다.
     하지만 이 정도의 성능 오버헤드마저 부담스러운 경우 모든 virtual로 지정하지 않는 것이 바람직하다.

   * virtual 소멸자의 필요성
     메서드를 모두 virtual로 선언하는 방식에 반대하는 프로그래머도 소멸자만큼은 virtual로 선언해야 한다고 생각한다.
     소멸자를 virtual로 선언하지 않으면 객체가 소멸할 때 메모리가 해제되지 않을 수 있기 때문이다.
     특별한 이유가 없거나 클래스를 final로 선언하지 않았다면 소멸자를 포함한 모든 메서드를 virtual로 선언한다. 
     단, 생성자는 virtual로 선언할 수 없고 그럴 필요도 없다. 객체를 생성할 때 항상 정확한 클래스를 지정하기 때문이다.

6. 오버라이딩 방지하기
   메서드로 final로 지정할 수 있다. 메서드를 final로 지정하면 파생 클래스에서 오버라이드할 수 없다.

### 10.2 코드 재사용을 위한 상속  
상속을 이용하면 기존에 작성된 코드를 그대로 활용할 수 있다.

2-1 WeatherPrediction 클래스  

2-2 파생 클래스에 기능 추가하기  

2-3 파생 클래스에서 기존 기능 변경하기  

### 10.3 부모를 공경해라  
파생 클래스를 작성할 때 반드시 부모 클래스와 자식 클래스의 연동 방식에 주의해야 한다. 생성 순서, 생성자 체이닝, 캐스팅 등에서 다양한 버그가 발생할 수 있기 때문이다.

3-1 부모 클래스의 생성자  
객체는 한번에 생성되지 않는다. 부모에 있던 것과 새로 추가할 내용을 모두 담아서 생성한다.
C++는 객체 생성 과정을 다음과 같이 정의하고 있다.

1. 베이스 클래스라면 디폴트 생성자를 실행한다. 단, 생성자 이니셜라이저가 있다면 디폴트 생성자 대신 생성자 이니셜라이저를 호출한다.
2. static으로 선언하지 않은 데이터 멤버를 코드에 나타난 순서대로 생성한다.
3. 클래스 생성자의 본문을 실행한다.
   
3-2 부모 클래스의 소멸자
소멸자는 인수를 받지 않기 때문에 부모 클래스의 소멸자는 언제나 자동으로 호출되게 할 수 있다. 소멸자의 호출 과정은 다음과 같이 생성자와 반대다.

1. 현재 클래스의 소멸자를 호출한다.
2. 현재 클래스의 데이터 멤버를 생성할 때와 반대 순서로 삭제한다.
3. 부모 클래스가 있다면 부모의 소멸자를 호출한다.

3-3 부모 클래스 참조하기
파생 클래스에서 메서드를 오버라이드하면 다른 코드가 볼 때 원본 코드를 바꾸는 효과가 나타난다. 하지만 그 메서드의 부모 버전은 그대로 남아 있기 때문에 얼마든지 실행할 수 있다.

3-4 업캐스팅과 다운캐스팅
객체를 부모 클래스 타입으로 캐스팅하거나 대입할 수 있다. 기존 객체를 캐스팅이나 대입하면 슬라이싱이 발생한다.
업 캐스팅 : 베이스 클래스 타입으로 파생 클래스를 참조하는 것
다운 캐스팅 : 베이스 클래스를 파생 클래스로 캐스팅하는 것(반드시 dynamic_cast를 활용하며 꼭 필요할 때만 사용)

### 10.4 다형성을 위한 상속  
순수 가상 메서드 : 클래스 정의 코드에서 명시적으로 정의하지 않는 메서드(파생 클래스에서 하나도 빠짐없이 구현해야 한다.)
추상 클래스 : 순수 가상 메서드가 최소한 하나라도 정의된 클래스

### 10.5 다중 상속  
5-1 여러 클래스 상속하기
다중 상속을 정의하는 방법 : 클래스 이름 옆에 상속할 베이스 클래스를 나열하기만 하면 된다.  

파생 클래스가 여러 부모 클래스를 동시에 상속하면 다음과 같은 속성을 갖게 된다.
* 파생 클래스는 부모 클래스들이 가지고 있는 데이터 멤버와 public 메서드를 가진다.
* 파생 클래스는 부모 클래스들의 protected 데이터 멤버와 메서드에 접근할 수 있다.
* 파생 클래스를 부모 클래스들로 업캐스팅할 수 있다.
* 파생 클래스를 생성하면 부모 클래스들의 디폴트 생성자가 호출된다.  
  이때 호출 순서는 첫 줄에 정의한 순서를 따른다.
* 파생 클래스를 삭제하면 부모 클래스들의 소멸자가 자동으로 호출된다.  
  이때 호출 순서는 클래스 클래스 정의에 나열한 클래스 순서와 반대다.

5-2 이름 충돌과 모호한 베이스 클래스  
1. 모호한 이름  
   2개의 부모 클래스가 있을 때 둘 다 eat() 메서드를 가지고 있을 경우 파생 클래스에서 eat()메서드를 호출하지 않는다면 문제가 되지는 않는다.  
   하지만 파생 클래스에서 eat() 메서드 호출 시 컴파일러가 어느 버전 eat()을 호출해야 하는지 판단할 수 없어 컴파일 에러가 발생한다.  
   이렇게 모호한 상황이 발생하지 않게 하려면 dynamic_cast()로 객체를 명시적으로 업캐스팅해서 원하지 않는 버전을 가리거나
   스코프 지정 연산자로 원하는 버전을 구체적으로 지정한다.

2. 모호한 베이스 클래스  
   같은 클래스를 두 번 상속할 때도 모호한 상황이 발생한다.
   클래스 계층이 다이아몬드 형태로 구성됐을 때(부모 클래스가 겹칠 때)는 최상단의 베이스 클래스를 가상 베이스 클래스로 만들면 된다.
   
3. 다중 상속 활용법  
   믹스인 클래스를 구현할 때
   컴포넌트 기반으로 클래스를 모델링할 때 

### 10.6 상속에 관련된 미묘하면서 흥미로운 문제들  
6-1 오버라이드한 메서드의 속성 변경하기  
1. 리턴 타입 변경하기
   오버라이드할 메서드는 베이스 클래스의 메서드 프로토타입과 똑같이 작성하는 것이 원칙이다.
   하지만 C++는 베이스 클래스의 리턴 타입이 다른 클래스에 대한 포인터나 레퍼런스 타입이면 메서드를 오버라이드할 때 리턴 타입을  
   그 클래스의 파생 클래스에 대한 포인터나 레퍼런스 타입으로 바꿀 수 있다. (관련 없는 타입은 변경 X) 이런 타입을 **공변 리턴 타입**이라 부르며  
   베이스 클래스와 파생 클래스가 병렬 계층(따로 존재하지만 어느 한쪽에 관련이 있을 때)을 이룰 때 유용할 수 있다.

   오버라이드하는 과정에서 원본 메서드의 리턴 타입을 변경해도 되는지 알아내기 위한 좋은 방법은 이렇게 바꿔도  
   기존코드가 제대로 작동하는지 확인하는 것이다. 이를 **리스코프 치환 원칙**이라 부른다.

2. 메서드 메개변수 변경하기  
   파생 클래스를 정의하는 코드에서 virtual 메서드를 선언할 때 이름은 부모 클래스에 있는 것과 똑같이 쓰고  
   매개변수만 다르게 지정하면 부모 클래스의 메서드가 오버라이드되는 것이 아니라 새로운 메서드가 정의된다.

   그러나 파생 클래스에서 프로토타입이 달라져도 실질적으로 베이스 클래스 버전을 상속하는 효과를 낼 수 있는 다소 특이한 테크닉이 있다.  
   파생 클래스에서 베이스 클래스 메서드를 정의하고 그 앞에 using 키워드를 명시적으로 지정하면 된다.

6-2 생성자 상속  
using 키워드로 베이스 클래스에 정의된 메서드를 파생 클래스에 명시적으로 지정하는 기법은 일반 클래스의 메서드뿐만 아니라 생성자에도 적용할 수 있다.

using 구문으로 베이스 클래스의 생성자를 상속할 때 몇 가지 제약사항이 있다.
베이스 클래스의 생성자를 상속하면 디폴트 생성자를 제외한 모든 생성자를 한꺼번에 상속한다.(일부만 상속 불가능)
여러 베이스 클래스에서 매개변수 목록이 똑같은 생성자는 상속할 수 없다.(해결하려면 충돌하는 생성자를 명시적으로 정의)

6-3 메서드 오버라이딩의 특수한 경우  
1. 베이스 클래스가 static인 경우  
   C++에서는 static 메서드를 오버라이드할 수 없다.
   메서드에 static과 virtual을 동시에 지정할 수 없다. static 메서드를 오버라이드 하면 원래 의도와 다른 효과가 발생한다.
   파생 클래스에 있는 static 메서드의 이름이 베이스 클래스의 static메서드와 같으면 서로 다른 메서드 두 개가 생성된다.

2. 베이스 클래스 메서드가 오버로드된 경우  
   베이스 클래스에 다양한 버전으로 오버로드된 메서드가 여러 개 있는데 그중 한 버전만 오버라이드하면  
   컴파일러는 베이스 클래스에 있는 다른 버전의 메서드도 함께 가려버린다.  
   이 경우 파생 클래스에서 다른 버전에 접근하는 방법은 파생 클래스 객체를 가르킬 부모 클래스의 포인터나 레퍼런스를 만들면 된다.

   실제로 수정(오버라이드)하고 싶은 버전은 하나뿐인 경우 using 키워드를 사용하여 간편하게 처리할 수 있다.
   하지만 주의할 점이 있는데 using 키워드를 사용하는 경우 명시적으로 오버라이드하지 않은 나머지 버전은 그대로 받아서 쓴다.  
   그래서 베이스 클래스에 메서드에 새로운 오버로딩 버전을 추가했는데 이 버전이 파생 클래스에서 오버라이드 해야 하는 경우  
   오버라이드 하지 않더라도 에러가 발생하지 않기 때문에 주의해야한다. 

# Part4  



***