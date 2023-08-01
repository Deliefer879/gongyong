# C Lang

* ## union
  * ��� ���� �� ���� �޸� �Ҵ緮�� ū ���� �ϳ��� ������ �Ҵ�  
    -> ����ü���� ������ : ����ü�� �� �ɹ� �������� ������ �Ҵ�
  *  ```cpp
        union student
        {
            int age;
            double grade;
        }
        ```
        * ���� ���� ����ü���� student���� ���� ū double(8����Ʈ)�� ����ü�� �Ҵ�
   *  **�޸� ������ �����ϱ� ������ ���Ͽ��� �ѹ��� �Ѱ��� �ɹ� ������ ����ؾ���**
</br></br>

* ## ����Ʈ ������
  * "<<" : ��Ʈ�� �������� �̵������ִ� ������ (A << 2 : A * 2^2)
  * ">>" : ��Ʈ�� �������� �̵������ִ� ������ (B >> 2 : B / 2^2)
</br></br>

* ## �� ������
  * and : 2�� �� T�� T
  * or  : 1����� T�� T
  * xor : ���� �ٸ��� T
</br></br>

* ## �޸� padding
  * Ŭ������ ����ü�� �е� ����Ʈ�� �߰��Ͽ� CPU ������ �����ϰ� ���ִ°�
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

  * ����ü�� ������� 24byte�� �ƴ϶� ���� ū �ڷ����� double�� �������� padding byte�� �� 32byte�� ����

  * ���� ���� padding byte�� ���� �������� ũ�Ⱑ Ŀ���� ���� �����ϱ� ���ؼ��� �������� ������ �߿��� 
     
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

  * ������ �ٲ㵵 32byte���� 24byte�� ũ�Ⱑ �پ��
</br></br>

* ## ����ȭ
    ������ ����� ������ ������� �����Ͽ� ó���ӵ� ���
</br></br>

 * ## inline �Լ�
    �Ϲ����� �Լ��� ȣ�� ������ ��ġ�� �ʰ�, �Լ��� ��� �ڵ带 ȣ��� �ڸ��� �ٷ� �����ϴ� ����� �Լ�  
  �Լ��� inline���� �ƴ����� �����Ϸ��� �Ǵ��ϸ� inline�� ���̴��� inline�Լ��� �ƴҼ��� �ִ�.  
  force inline�� ���̸� ������ inline�Լ��� �ȴ�.
</br></br>

* ## const
  *  *�� �������� =>  ��(���ʿ� const) <- * -> �ּ� (�����ʿ� const)  
  * const int* ptr = �� ���� X
  * int* const ptr = �ּ� ���� X
  * const int* const ptr = ��, �ּ� �� �� ���� X
  * const�� ������ ������� * ���� ����, �������� �߿��ϴ�.
  * const �ɹ� ������ �������� �ɹ� �̴ϼ� ��������� �ʱ�ȭ�� �����ϴ�.

  * const �Լ� : Ŭ���� �ɹ� ������ ���� �������� ���ϴ� �Լ��� const�Լ������� const�� �ƴ� �Ϲ� �Լ��� ȣ�� �Ұ���
</br></br>

* C++������ malloc, free�� ��밡���ϴ� ������ �� ���Լ��� �̿��� �ν��Ͻ� ���� �� �����ڿ� �Ҹ��ڰ� ȣ����� �ʴ´�.
</br></br>


* ## virtual �Լ�
  �Լ��� virtual Ű���带 ���̸� ������ ���� ���̺��� �����Ǿ� �ڽ� Ŭ�������� �Լ� ������ ��  
  �������� �Լ��� �ּҷ� ���� ���ε��Ǿ� �θ� Ŭ������ �����ͷ� �Լ� ȣ���� �Ͽ��� �ڽ� Ŭ������ �Լ��� ȣ��ȴ�.  
  ���� C++������ virtual �Լ��� ���� ���ΰ� �������� ������ ��ġ�Ƿ� �ٸ� Ŭ�������� ����� �޴� ���  
  �Ҹ��ڿ� vitual Ű���带 �ʼ������� �������ִ� ���� ����. �׸��� virtual�� �ڽĿ��� �ڵ����� ����ȴ�.
</br></br>

* ## ���� virtual �Լ�
   ```cpp
      /*
        class A�� Func()�� ���� �����Լ��̱� ������ ���� �ν��Ͻ��� ������ �� ������
        �ڽ� Ŭ���������� �ݵ�� Func()�� ������ ���־�� �Ѵ�.

        ���� virtual �Լ��� �߻� Ŭ������ ����� �뵵���ٴ� �������̽��� ����� �뵵�� ������.
      */
      class A
      {
      private:
        int x;
        int y;

      public:
        A(int x, int y);          // ������
        virtual ~A();             // virtual �Ҹ���
        virtual void Func() = 0;  // ���� virtual �Լ�
      };
    ```
    </br></br>

* ## ���� ó��
  * ���� ���� ���� ����ó�� : return 0 �� ���� �Լ��� return ���� �̿��� ���� ó���� �ϴ� �������  
  ���� �߻��� ���� ������ �޽����� Ÿ���� ������ ����
  * throw�� ���� ���� ó�� : throw catch�� ����ϴ� ������� throw�� �� �ִ� Ÿ�Կ� ������ ����.  
  �� void �Լ��� ���� �Լ��� return ���� ������ ���� �޽����� ������ �� ������  
  catch���� overloading�Ͽ� switch case���� ���� ����� �����ϴ�  
  
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
  * cast�� ���� ����ϴ� �� ���ٴ� ������(virtual ��)�� Ȱ���� ���� ���°� ����.
  * dynamic_cast< T >(expr) : �Ϻ� ��ȣ�԰� ���輺�� �����ϴ� �� ������ �ִ�.
    * ������ ������ ��ȯ�ϴµ� ���Ǹ� ��ĳ��Ʈ�� �Ѵ�.
    * ���н� null ��ȯ�Ѵ�.
    * static_cast���� ���� �ӵ��� ������ �����ϴ�.
    * ��� ���迡 **�ݵ��** virtual�� �־�� �Ѵ�.
    * ```cpp
      // A -> B -> C

      void Globaltest(A& a) {
        try {
          C &c = dynamic_cast<C&>(a);		// & Ÿ���� null�� �ʱ�ȭ �Ұ���
          printf_s("in GlobalTest\n");
        }
        catch (std::bad_cast) {         // A& a�� A&, B&�� �ð�� bad_cast ���� �߻�
          printf_s("Can't cast to C\n");
        }
      }

      int main() {
        A *pa = new C;
        A *pa2 = new B;

        pa->test();

        B * pb = dynamic_cast<B *>(pa); // ���� �޸𸮴� C�̱� ������ ���� X
        if (pb)
          pb->test2();                  // ����

        C * pc = dynamic_cast<C *>(pa2); // ���� �޸𸮴� B�̱� ������ null
        if (pc)
          pc->test2();                  // ���� X

        C ConStack;
        Globaltest(ConStack); // ���� X

        B BonStack;
        Globaltest(BonStack); // bad_cast!
      }
      ```



  * static_cast< T >(expr) : Ŭ���� �� ������, �⺻ �ڷ��� ���� ���� ���� ����ȯ
    * �� å���� ���� ������ ��Ÿ�� ������ �߻��� �� �ִ�. (�����Ͽ��� ���� ����)
    * base Ŭ�������� derived Ŭ�������� �ٿ� ĳ���� ������ ��ȯ ���꿡 ��밡�� �׷��� �׻� ������ ���� �ƴ�
    * �޸� ħ�� ����
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

        Derived* t1 = static_cast<Derived*>(base); //�ٿ� ĳ����
        base*    t2 = static_cast<Base*>(derived); //�� ĳ����

        t1.derived1 = 9; // �ٿ� ĳ���� �� �ڽ��� �ɹ��� ���ٽ� � ������ �߻����� �𸥴�!
                         // null ������ ����� �ְ� �ϴ� free�޸𸮸� ����� ���α׷��� ���ư�����
                         // ���� �� ������ �ɼ��� �ִ�.
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
          // BClass�� �ɽ��õǴ� ����� �˷��ش�. (�� �� ������ ������� �ʴ°� ����!)
          operator BClass();
        };
        AClass::operator BClass()
        {
          // ����ʱ�ȭ
          BClass fRet = { static_cast<float>(m_iValue) };
          return fRet;
        };

        void main()
        {
          AClass a;
          a.m_iValue = 99;
          BClass b;
          b.m_fValue = -1;

          // ��Ӱ��谡 ��� �ɽ��� �ȴ�.(�Ҿ���) C ��Ÿ�� ĳ����
          AClass * pa = (AClass*)&b;
          // ��Ӱ��谡 ������ ������ ������ �ȴ�.
          ///pa = static_cast<AClass*>(&b); // 

          // static_cast �� ����ȯ ����� �˸� ��ȯ�Ѵ�.
          // �׷��� ����� �𸣸� �˷���� �Ѵ�.
          c = static_cast<BClass>(a); // class A�� ������ operator BClass ���п� AClass��
                                      // ���� ��� ���� Ŭ���� BClass�� ����ȯ �Ǿ���.
          int k = c.m_fValue;

        }
        ```
        </br></br>

  * const_Cast< T >(expr) : const ������ �����ϴµ� ���ȴ�.
    * �ܼ��� ��ȯ���� const�� �����ϴ� ���� �ƴ϶� �� Ȱ���ϸ� const �Լ� ���ο��� ���� �����ϰų� �Ϲ� �Լ��� ȣ���Ҽ��� �ִ�.
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
      // ����Լ� const �� ������ Ŭ���� ��ü�� ���ȭ�ȴ�.
      void CCTest::printNumber() const {
        cout << "\nBefore: " << number;
        const_cast< CCTest * >(this)->number--; // const_cast�� ����� const �Լ� ���ο���
                                                // �ɹ� ������ ���� �����Ͽ���.
                                                // ���� const_cast�� ����Ͽ� �Ϲ� �Լ��� ȣ���Ҽ��� �ִ�.
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
        //rror C2440: '�ʱ�ȭ ��': 'const int *'���� 'int *'(��)�� ��ȯ�� �� �����ϴ�.
        //int* iValue3 = X.GetConst();
        //1
        const int* iValue = X.GetConst();
        //*iValue = 20; //  ��� ����
        //2
        int* iValue2 = const_cast<int*>(X.GetConst());
        *iValue2 = 20;

        X.printNumber();
      }
      ```
      </br></br>

  * reinterpret_cast< T >(expr) : �ƹ� ������� �ڷ������� �� ��ȯ�ϴµ� ��밡���ϴ�.
    * void* �� ����� ���ҷ� ��밡���ϴ�.
    * �ַ� �ּ��� ��ġȭ� ����Ѵ�.
    * ������ Ŭ������ int�ε� ��ȯ�� ������������ ������ ��������� �׸�ŭ ������ ����̴�.
    
  </br></br>

* ## �̵� ������, �̵� ���� ������
  * C++���� ��� ǥ������ Lvalue or Rvalue �̴�.
    * Lvalue : �޸� �󿡼� �����ϴ� ����(�ּҰ��� ���� �� ����), ǥ������ ����, ������ ��� �� �� �ִ�.
    * Rvalue : �ӽ� �޸𸮿� ��� �����ϴ� ����(�ּҰ��� ���� �� ����), ǥ������ �����ʿ� �����ؾ� ��
  * Rvalue�� &(left reference)�� �Ұ����ϴ�. ������ C++ 11���� &&(right reference)�� �߰��Ǿ�  
    Rvalue�� ������ �����ϴ�. **ex) int&& a = 3;**
  * �̵� ������
    * �̵� �����ڴ� Rvalue�� ���ڷ� �޴� �������̴�.  
      (������ left reference�� �� ���ް� ��ȣ���� �������� right referenceȰ���ϸ� ������ �����ϴ�.)
    * �̵� ������ : ���� ������ó�� ��ü�� ���� �� �ٸ� ��ü�� �����͸� ���� �����ϴ� ���� �ƴ϶�,  
      Rvalue�� �����Ϳ� ���� ���縦 ������ �� Rvalue�� �����͸� NULL�� �����ϴ� �������� �����ϴ� ����� �������̴�.
    * ���� ���� ���� ������ ������ �ӽ� ��ü�� �ּҴ� stack�� �������� ������ �Ű� ������ heap�� ���� �� �ֱ� �����̴�.(stack�� heap�� ����Ű�� ����)
  * �̵� ���� ������
    * �̵� ���� �����ڴ� Rvalue�� ���ڷ� �޴� ���� �������̴�.
    * �̵� ���� ������ : ���� ���� ������ó�� ��ü�� ���� �� �ٸ� ��ü�� �����͸� ���� �����ϴ� ���� �ƴ϶�,  
      Rvalue�� �����Ϳ� ���� ���縦 ������ �� Rvalue�� �����͸� NULL�� �����ϴ� �������� �����ϴ� ����� ���� �������̴�.
  * std::move(expr) : expr�� Rvalue�� ĳ�����Ѵ�.
    * �̵� �����ڿ� �̵� ���� �����ڸ� ȣ���ϱ� ���ؼ��� Rvalue�� �ʿ��ϴ�.  
      �׷��� Rvalue�� ���ڷ� �޴� �����ڿ� ���� �����ڸ� ȣ���ϱ� ���ؼ��� Lvalue�� Rvalue�� ĳ�����ؾ� �Ѵ�.  
      �̶� ����ϴ� ���� std::move(expr)�̴�.
    * std::move(expr)�� expr�� Rvalue�� ĳ�����Ѵ�.  
      ��, expr�� Rvalue�̸� �״�� Rvalue�� ĳ�����ϰ�, Lvalue�̸� Rvalue�� ĳ�����Ͽ� ��ȯ�Ѵ�.
    * std::move(expr)�� expr�� Rvalue�� ĳ������ �� ��ȯ�Ѵ�.  
      ���� std::move(expr)�� ��ȯ�� Rvalue�� �̵� �����ڿ� �̵� ���� �������� ���ڷ� �����ϸ�  
      �̵� �����ڿ� �̵� ���� �����ڰ� ȣ��ȴ�.

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
  * auto : ������ Ÿ���� �ڵ����� �߷����ִ� ����̴�.
  * decltype : ǥ������ Ÿ���� �߷����ִ� ����̴�.
  * ```cpp
      auto ret = Get();
      //int (*Func)() = Get;
      auto Func = Get;        // same as above line
      Func();

      // �����Ϸ� ����(�߷�)
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
  * lambda�� �͸��Լ��� ������ִ� ����̴�.
  * lambda�� �Լ��� �����ϴ� ���� �ƴ϶� �Լ��� ������ ���̴�.
  * lambda�� �Լ��� ������ ���̱� ������ �Լ��� ���ڷ� �Ѱ��� �� �ִ�.
  * lambda�� �Լ��� ������ ���̱� ������ �Լ��� ��ȯ������ ����� �� �ִ�.

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
  * SOLID�� ��ü ���� ���α׷����� ���� ��Ģ�� ��Ÿ���� 5���� ��Ģ�� �ձ��ڸ� �� ���̴�.
      * Single Responsibility Principle (���� å�� ��Ģ)
        * �ϳ��� Ŭ������ �ϳ��� å�Ӹ� ������ �Ѵ�. (Ŭ���� �и�)
        * �ϳ��� å���̶�� ���� ��ȣ�ϴ�. Ŭ���̾�Ʈ�� ����� ���� ���信 ���� �޶�����.  
          ��, ������ �� �� �ִ� �κ��� �������� ���� å���� ������ �Ѵ�.
      * Open-Closed Principle (����-��� ��Ģ)
        * Ȯ�忡�� �����ְ�, ���濡�� �����־�� �Ѵ�. (��� + ���� �Լ�) 
        * ������ �ڵ带 �������� �����鼭 ����� �߰��� �� �ֵ��� ���谡 �Ǿ�� �Ѵ�.
          (����� ���� ����� �߰��ϰ�, ������ �ڵ带 �������� �ʴ´�.(�������� �����Ѵ�))
      * Liskov Substitution Principle (�������� ġȯ ��Ģ)
        * �ڽ� Ŭ������ �ּ��� �ڽ��� �θ� Ŭ�������� ������ ������ ������ �� �־�� �Ѵ�.
        * �ڽ� Ŭ������ �θ� Ŭ������ ������ ��ü�� �� �־�� �Ѵ�.
      * Interface Segregation Principle (�������̽� �и� ��Ģ)
        * �ڽ��� ������� �ʴ� �������̽��� �������� ���ƾ� �Ѵ�.
        * �ϳ��� �Ϲ����� �������̽����ٴ�, ���� ���� ��ü���� �������̽��� ����.
        * �ټ��� ����� ���õ� ���� ����� �и��ؼ� Ŭ������ ������.  
          �и��� Ŭ������ �ش��ϴ� ����� ���ؼ� ���ʿ��� ������ �� ����� �Ƚᵵ �ȴ�.
      * Dependency Inversion Principle (���� ���� ��Ģ)
        * ��ü���� Ŭ�������� �������̽��� �߻� Ŭ������ ���� ���踦 �ξ��.
        * �θ� Ŭ������ �������̽��� ���ؼ� ����� ����ϵ��� �Ѵ�.  

������ ���� : if_else�� ���ִ� ���� ����, ������(���, virtual)�� �̿��ؼ� if_else�� ���ش�.

����ȭ : ���� ���ɼ� �ִ� �ڵ�� �Ѱ����� ��� ������ ���ϰ� �Ѵ�










