# C Lang

* ## union
  * 멤버 변수 중 가장 메모리 할당량이 큰 변수 하나의 공간만 할당  
    -> 구조체와의 차이점 : 구조체는 각 맴버 변수마다 공간이 할당
  *  ```cpp
        union student
        {
            int age;
            double grade;
        }
        ```
        * 위와 같은 공용체에서 student에는 가장 큰 double(8바이트)만 공용체에 할당
   *  **메모리 공간을 공유하기 때문에 유니온은 한번에 한개의 맴버 변수만 사용해야함**
</br></br>

* ## 쉬프트 연산자
  * "<<" : 비트를 좌측으로 이동시켜주는 연산자 (A << 2 : A * 2^2)
  * ">>" : 비트를 우측으로 이동시켜주는 연산자 (B >> 2 : B / 2^2)
</br></br>

* ## 논리 연산자
  * and : 2개 다 T면 T
  * or  : 1개라고 T면 T
  * xor : 값이 다르면 T
</br></br>

* ## 메모리 padding
  * 클래스나 구조체에 패딩 바이트를 추가하여 CPU 접근을 용이하게 해주는것
  * ex) 
    * ```cpp
      struct t
      {
        int a;
        double b;
        int c;
        double d;
      }
      ```

      |||||||||
      |----------|----------|----------|----------|----------|----------|----------|----------|
      | int a    | int a    | int a    | int a    | padding  | padding  | padding  | padding  |
      | double b | double b | double b | double b | double b | double b | double b | double b |
      | int c    | int c    | int c    | int c    | padding  | padding  | padding  | padding  |
      | double d | double d | double d | double d | double d | double d | double d | double d |

  * 구조체의 사이즈는 24byte가 아니라 가장 큰 자료형인 double을 기준으로 padding byte가 들어가 32byte가 나옴

  * 위와 같이 padding byte에 의해 데이터의 크기가 커지는 것을 방지하기 위해서는 데이터의 순서가 중요함 
     
  * ex)
    * ```cpp
      struct t
      {
        double b;
        double d;
        int a;
        int c;
      }
      ```

      |||||||||
      |----------|----------|----------|----------|----------|----------|----------|----------|
      | double b | double b | double b | double b | double b | double b | double b | double b |
      | double d | double d | double d | double d | double d | double d | double d | double d |
      | int a    | int a    | int a    | int a    | int c    | int c    | int c    | int c    |

  * 순서만 바꿔도 32byte에서 24byte로 크기가 줄어듬
</br></br>

* ## 정적화
    로직의 결과가 같을때 결과값을 저장하여 처리속도 향상
</br></br>

 * ## inline 함수
    일반적인 함수의 호출 과정을 거치지 않고, 함수의 모든 코드를 호출된 자리에 바로 삽입하는 방식의 함수  
  함수가 inline인지 아닌지는 컴파일러가 판단하며 inline을 붙이더라도 inline함수가 아닐수도 있다.  
  force inline을 붙이면 무조건 inline함수가 된다.
</br></br>

* ## const
  *  *를 기준으로 =>  값(왼쪽에 const) <- * -> 주소 (오른쪽에 const)  
  * const int* ptr = 값 변경 X
  * int* const ptr = 주소 변경 X
  * const int* const ptr = 값, 주소 둘 다 변경 X
  * const는 개수와 상관없이 * 기준 왼쪽, 오른쪽이 중요하다.
  * const 맴버 변수는 생성자의 맴버 이니셜 라이즈에서만 초기화가 가능하다.

  * const 함수 : 클래스 맴버 변수의 값을 변경하지 못하는 함수로 const함수에서는 const가 아닌 일반 함수를 호출 불가능
</br></br>

* C++에서도 malloc, free를 사용가능하다 하지만 이 두함수를 이용해 인스턴스 생성 시 생성자와 소멸자가 호출되지 않는다.
</br></br>


* ## virtual 함수
  함수에 virtual 키워드를 붙이면 별도의 가상 테이블이 생성되어 자식 클래스에서 함수 재정의 시  
  재정의한 함수의 주소로 동적 바인딩되어 부모 클래스의 포인터로 함수 호출을 하여도 자식 클래스의 함수가 호출된다.  
  또한 C++에서는 virtual 함수의 존재 여부가 다형성에 영향을 미치므로 다른 클래스에서 상속을 받는 경우  
  소멸자에 vitual 키워드를 필수적으로 선언해주는 것이 좋다. 그리고 virtual은 자식에도 자동으로 적용된다.
</br></br>

* ## 순수 virtual 함수
   ```cpp
      /*
        class A는 Func()가 순수 가상함수이기 때문에 직접 인스턴스로 생성할 수 없으며
        자식 클래스에서는 반드시 Func()를 재정의 해주어야 한다.

        순수 virtual 함수는 추상 클래스를 만드는 용도보다는 인터페이스를 만드는 용도에 가깝다.
      */
      class A
      {
      private:
        int x;
        int y;

      public:
        A(int x, int y);          // 생성자
        virtual ~A();             // virtual 소멸자
        virtual void Func() = 0;  // 순수 virtual 함수
      };
    ```
    </br></br>

* ## 예외 처리
  * 리턴 값에 의한 예외처리 : return 0 와 같이 함수의 return 값을 이용해 예외 처리를 하는 방식으로  
  예외 발생시 전송 가능한 메시지의 타입이 정해져 있음
  * throw에 의한 예외 처리 : throw catch를 사용하는 방식으로 throw할 수 있는 타입에 제한이 없다.  
  즉 void 함수와 같이 함수의 return 값이 없더라도 예외 메시지를 전달할 수 있으며  
  catch문을 overloading하여 switch case문과 같이 사용이 가능하다  
  
  * ```cpp  
    #include <iostream>
    #include <string>

    using namespace std;

    void TestException();
    void TestException2() throw(MyException); // show throw exception type
                                              // it is not sentance, but a declaration
    int main() {
        try {
            TestException(); // this function will elemintate by exception
                            // because TestException2() will throw exception
                            // and TestException() does not handle it
        }
        catch (MyException& e) { // throw exception is handled by nearest catch
            e.what();            // judged by stack block
        }
        catch (...) {           // catch all exception
            cout << "unknown exception" << endl;
        }

        return 0;
    }

    class MyException {
    public:
        MyException(string message) { e_data = message; }
        MyException() { e_data = "base exception";}

        ~MyException() { }

        void what() {
            cout << e_data << endl;
        }

    private:
        string e_data;
    };

    void TestException() {
        int* a = new int;

        TestException2(); // this line will throw exception
                          // if TestException() has catch block, it will be handled
                          // and it can throw exception again to main()

        delete a;   // this line will not be executed if exception is thrown
                    // so memory leak will occur
    }

    void TestException2() {
        throw MyException("test exception");
    }
    ```

  </br></br>


* ## cast
  * cast를 많이 사용하는 것 보다는 다형성(virtual 등)을 활용해 조금 쓰는게 좋다.
  * dynamic_cast< T >(expr) : 일부 모호함과 위험성을 제거하는 데 목적이 있다.
    * 다형성 형식을 변환하는데 사용되며 업캐스트라 한다.
    * 실패시 null 반환한다.
    * static_cast보다 연산 속도가 빠르며 안전하다.
    * 상속 관계에 **반드시** virtual이 있어야 한다.
    * ```cpp
      // A -> B -> C

      void Globaltest(A& a) {
        try {
          C &c = dynamic_cast<C&>(a);		// & 타입은 null로 초기화 불가능
          printf_s("in GlobalTest\n");
        }
        catch (std::bad_cast) {         // A& a가 A&, B&로 올경우 bad_cast 예외 발생
          printf_s("Can't cast to C\n");
        }
      }

      int main() {
        A *pa = new C;
        A *pa2 = new B;

        pa->test();

        B * pb = dynamic_cast<B *>(pa); // 실제 메모리는 C이기 때문에 문제 X
        if (pb)
          pb->test2();                  // 실행

        C * pc = dynamic_cast<C *>(pa2); // 실제 메모리는 B이기 때문에 null
        if (pc)
          pc->test2();                  // 실행 X

        C ConStack;
        Globaltest(ConStack); // 예외 X

        B BonStack;
        Globaltest(BonStack); // bad_cast!
      }
      ```



  * static_cast< T >(expr) : 클래스 및 참조형, 기본 자료형 간의 조건 없는 형변환
    * 단 책임이 없기 때문에 런타임 오류가 발생할 수 있다. (컴파일에서 오류 검출)
    * base 클래스에서 derived 클래스로의 다운 캐스팅 포인터 변환 연산에 사용가능 그러나 항상 안전한 것은 아님
    * 메모리 침범 문제
    * ```cpp
      class Base
      {
        public:
          int base1;
          int base2;
      }

      class Derived
      {
        public:
          int derived1;
          int derived2;
      }
      void main()
      {
        Base* base = new Base;
        Derived* derived = new Derived;

        Derived* t1 = static_cast<Derived*>(base); //다운 캐스팅
        base*    t2 = static_cast<Base*>(derived); //업 캐스팅

        t1.derived1 = 9; // 다운 캐스팅 후 자식의 맴버의 접근시 어떤 에러가 발생할지 모른다!
                         // null 참조가 뜰수도 있고 일단 free메모리를 사용해 프로그램은 돌아가지만
                         // 종료 시 문제가 될수도 있다.
      }
      ```

    * static_cast operator
    * ```cpp
        class BClass
        {
        public:
          float m_fValue;
        };
        class AClass
        {
        public:
          int m_iValue;
          // BClass로 케스팅되는 방법을 알려준다. (될 수 있으면 사용하지 않는게 좋음!)
          operator BClass();
        };
        AClass::operator BClass()
        {
          // 멤버초기화
          BClass fRet = { static_cast<float>(m_iValue) };
          return fRet;
        };

        void main()
        {
          AClass a;
          a.m_iValue = 99;
          BClass b;
          b.m_fValue = -1;

          // 상속관계가 없어도 케스팅 된다.(불안전) C 스타일 캐스팅
          AClass * pa = (AClass*)&b;
          // 상속관계가 없으면 컴파일 오류가 된다.
          ///pa = static_cast<AClass*>(&b); // 

          // static_cast 는 형변환 방법을 알면 변환한다.
          // 그러나 방법을 모르면 알려줘야 한다.
          c = static_cast<BClass>(a); // class A에 정의한 operator BClass 덕분에 AClass가
                                      // 전혀 상관 없는 클래스 BClass로 형변환 되었다.
          int k = c.m_fValue;

        }
        ```
        </br></br>

  * const_Cast< T >(expr) : const 선언을 제거하는데 사용된다.
    * 단순히 반환값의 const를 제거하는 것이 아니라 잘 활용하면 const 함수 내부에서 값을 변경하거나 일반 함수를 호출할수도 있다.
    * ```cpp
      #include <iostream>

      using namespace std;
      class CCTest {
      public:
        void setNumber(int);
        void printNumber() const;
        const int* GetConst();
      private:
        int number;
      };

      void CCTest::setNumber(int num) { number = num; }
      // 멤버함수 const 가 붙으면 클래스 자체가 상수화된다.
      void CCTest::printNumber() const {
        cout << "\nBefore: " << number;
        const_cast< CCTest * >(this)->number--; // const_cast를 사용해 const 함수 내부에서
                                                // 맴버 변수의 값을 변경하였다.
                                                // 또한 const_cast를 사용하여 일반 함수를 호출할수도 있다.
        cout << "\nAfter: " << number;
      }
      const int* CCTest::GetConst()
      {
        return &number;
      }
      int main() 
      {
        CCTest X;
        X.setNumber(8);
        //rror C2440: '초기화 중': 'const int *'에서 'int *'(으)로 변환할 수 없습니다.
        //int* iValue3 = X.GetConst();
        //1
        const int* iValue = X.GetConst();
        //*iValue = 20; //  상수 에러
        //2
        int* iValue2 = const_cast<int*>(X.GetConst());
        *iValue2 = 20;

        X.printNumber();
      }
      ```
      </br></br>

  * reinterpret_cast< T >(expr) : 아무 상관없는 자료형으로 형 변환하는데 사용가능하다.
    * void* 와 비슷한 역할로 사용가능하다.
    * 주로 주소의 수치화등에 사용한다.
    * 임의의 클래스를 int로도 변환이 가능할정도로 강력한 기능이지만 그만큼 위험한 기능이다.
    
  </br></br>

* ## 이동 생성자, 이동 대입 연산자
  * C++에서 모든 표현식은 Lvalue or Rvalue 이다.
    * Lvalue : 메모리 상에서 존재하는 변수(주소값을 취할 수 있음), 표현식의 왼쪽, 오른쪽 모두 올 수 있다.
    * Rvalue : 임시 메모리에 잠깐 존재하는 변수(주소값을 취할 수 없음), 표현식의 오른쪽에 존재해야 함
  * Rvalue는 &(left reference)가 불가능하다. 하지만 C++ 11부터 &&(right reference)가 추가되어  
    Rvalue도 참조가 가능하다. **ex) int&& a = 3;**
  * 이동 생성자
    * 이동 생성자는 Rvalue를 인자로 받는 생성자이다.  
      (기존의 left reference는 값 전달과 모호성이 생기지만 right reference활용하면 구분이 가능하다.)
    * 이동 생성자 : 복사 생성자처럼 객체를 생성 후 다른 객체의 데이터를 깊은 복사하는 것이 아니라,  
      Rvalue의 데이터에 얕은 복사를 수행한 후 Rvalue의 데이터를 NULL로 설정하는 소유권을 이전하는 방식의 생성자이다.
    * 위와 같은 일이 가능한 이유는 임시 객체의 주소는 stack에 있을지라도 내부의 매개 변수는 heap에 있을 수 있기 때문이다.(stack이 heap을 가리키고 있음)
  * 이동 대입 연산자
    * 이동 대입 연산자는 Rvalue를 인자로 받는 대입 연산자이다.
    * 이동 대입 연산자 : 복사 대입 연산자처럼 객체를 생성 후 다른 객체의 데이터를 깊은 복사하는 것이 아니라,  
      Rvalue의 데이터에 얕은 복사를 수행한 후 Rvalue의 데이터를 NULL로 설정하는 소유권을 이전하는 방식의 대입 연산자이다.
  * std::move(expr) : expr을 Rvalue로 캐스팅한다.
    * 이동 생성자와 이동 대입 연산자를 호출하기 위해서는 Rvalue가 필요하다.  
      그러나 Rvalue를 인자로 받는 생성자와 대입 연산자를 호출하기 위해서는 Lvalue를 Rvalue로 캐스팅해야 한다.  
      이때 사용하는 것이 std::move(expr)이다.
    * std::move(expr)은 expr을 Rvalue로 캐스팅한다.  
      즉, expr이 Rvalue이면 그대로 Rvalue로 캐스팅하고, Lvalue이면 Rvalue로 캐스팅하여 반환한다.
    * std::move(expr)은 expr을 Rvalue로 캐스팅한 후 반환한다.  
      따라서 std::move(expr)이 반환한 Rvalue를 이동 생성자와 이동 대입 연산자의 인자로 전달하면  
      이동 생성자와 이동 대입 연산자가 호출된다.

  * ```cpp

      #include <iostream>

      class Temp
      {
      private:
          int a;
      public:
          Temp() { std::cout << "Temp()" << std::endl; }
          Temp(int a) { this->a = a; std::cout << "Temp(int)" << std::endl; }
          Temp(const Temp&) { std::cout << "Temp(const Temp&)" << std::endl; } // copy constructor
          Temp(Temp&&) { std::cout << "Temp(Temp&&)" << std::endl; }           // move constructor
          ~Temp() { std::cout << "~Temp()" << std::endl; }

          Temp &operator=(const Temp&) { std::cout << "operator=(const Temp&)" << std::endl; return *this; }  // copy assignment
          Temp &operator=(Temp&&) { std::cout << "operator=(Temp&&)" << std::endl; return *this; }            // move assignment
      };

      // function return a temporary object(right value)
      Temp getTemp()
      {
          return Temp();
      }

      // this function can't be use toghether with the reference function 
      // void Function(Temp t)
      // {
      //     std::cout << "Function(Temp)" << std::endl;
      // }

      void Function(const Temp& t)
      {
          std::cout << "Function(const Temp&)" << std::endl;
      }

      void Function(Temp&& t)
      {
          std::cout << "Function(Temp&&)" << std::endl;
      }

      /// pointer can be use toghether with the reference function
      void Function(Temp* t)
      {
          std::cout << "Function(Temp*)" << std::endl;
      }

      int main()
      {
          Temp t1;                        // default constructor
          Temp t2 = t1;                   // copy constructor
          Temp t3 = Temp(1);              // move constructor
          Temp&& t4 = Temp(1);            // just a right reference
          Temp t5 = getTemp();            // move constructor
          Temp t6 = std::move(Temp(1));   // move constructor
          Temp&& t7 = std::move(Temp(1)); // just a right reference

          Temp* p = new Temp;

          Function(p);   // Function(Temp*)
          Function(*p);   // Function(const Temp&)
          Function(std::move(*p));   // Function(Temp&&)

          return 0;
      }

    ```
</br></br>

* auto, decltype
  * auto : 변수의 타입을 자동으로 추론해주는 기능이다.
  * decltype : 표현식의 타입을 추론해주는 기능이다.
  * ```cpp
      auto ret = Get();
      //int (*Func)() = Get;
      auto Func = Get;        // same as above line
      Func();

      // 컴파일러 결정(추론)
      decltype(3) myInt = 5;
      decltype("str") myString = "str";
      decltype(3.14) myFloat = 3.14;

      
      template<typename t1, typename t2>
      auto add(t1 a, t2 b)-> decltype(a+b)  // return type is same as a+b -> decltype(a+b) is optional but if we use it
      {                                     // we don't have to change the return type when we change the return type of a+b
          return (a + b);                   
      }
    ```

</br></br>

* ## lambda
  * lambda는 익명함수를 만들어주는 기능이다.
  * lambda는 함수를 정의하는 것이 아니라 함수를 만들어내는 것이다.
  * lambda는 함수를 만들어내는 것이기 때문에 함수의 인자로 넘겨줄 수 있다.
  * lambda는 함수를 만들어내는 것이기 때문에 함수의 반환값으로 사용할 수 있다.

  * ```cpp

      #include <iostream>

      int main()
      {
          // lambda
          auto f1= []() { return 5; };
          auto f2 = [] { return 5};          // can use without () 
          auto f3 = []() -> int { return 5}; // set return type
          
          // lambda with capture (capture = [])
          int a = 1;
          auto f4 = [a](int b) { return a += b; };  // capture by value
          auto f5 = [&a](int b) { return a += b; }; // capture by reference

          std::cout << f4(2) << std::endl; // a = 1
          std::cout << f5(2) << std::endl; // a = 3

          // function pointer
          int (*fp)(int, int) = [](int a, int b) { return a + b; };
          std::cout << fp(1, 2) << std
    ```
</br></br>

* ## SOLID
  * SOLID는 객체 지향 프로그래밍의 설계 원칙을 나타내는 5가지 원칙의 앞글자를 딴 것이다.
      * Single Responsibility Principle (단일 책임 원칙)
        * 하나의 클래스는 하나의 책임만 가져야 한다. (클래스 분리)
        * 하나의 책임이라는 것은 모호하다. 클라이언트나 변경과 같은 개념에 따라 달라진다.  
          즉, 변경이 될 수 있는 부분을 기준으로 단일 책임을 가져야 한다.
      * Open-Closed Principle (개방-폐쇄 원칙)
        * 확장에는 열려있고, 변경에는 닫혀있어야 한다. (상속 + 가상 함수) 
        * 기존의 코드를 변경하지 않으면서 기능을 추가할 수 있도록 설계가 되어야 한다.
          (상속을 통해 기능을 추가하고, 기존의 코드를 변경하지 않는다.(조건절을 제거한다))
      * Liskov Substitution Principle (리스코프 치환 원칙)
        * 자식 클래스는 최소한 자신의 부모 클래스에서 가능한 행위는 수행할 수 있어야 한다.
        * 자식 클래스는 부모 클래스의 역할을 대체할 수 있어야 한다.
      * Interface Segregation Principle (인터페이스 분리 원칙)
        * 자신이 사용하지 않는 인터페이스는 구현하지 말아야 한다.
        * 하나의 일반적인 인터페이스보다는, 여러 개의 구체적인 인터페이스가 낫다.
        * 다수의 기능을 관련된 공통 기능을 분리해서 클래스로 만들어라.  
          분리된 클래스에 해당하는 상속을 통해서 불필요한 데이터 및 기능을 안써도 된다.
      * Dependency Inversion Principle (의존 역전 원칙)
        * 구체적인 클래스보다 인터페이스나 추상 클래스와 의존 관계를 맺어라.
        * 부모 클래스나 인터페이스를 통해서 기능을 사용하도록 한다.  

디자인 패턴 : if_else를 없애는 것이 목적, 다형성(상속, virtual)을 이용해서 if_else를 없앤다.

국지화 : 변경 가능성 있는 코드는 한곳으로 모아 관리가 편하게 한다










