# STL

* ## vector
  * Queue를 동적 배열 구조를 구현한 구조
  * array와 달리 자료수에 따라 크기가 자동으로 늘어남
  * 자료의 삽입, 삭제가 빈번하게 일어나는 경우 List를 사용하는 것이 좋음
  * 배열이기 때문에 emplace등을 사용해 앞이나 중간에 자료 삽입 시 뒤의 자료들을 한칸씩 뒤로 밀어야 하기 때문에 비효율적
  * List와 달리 메모리가 연속적으로 할당되어 있기 때문에 메모리 접근이 빠르며 index 접근이 가능함(List는 불가능)
  * 메모리 할당이 일어날 때 기존 메모리의 데이터를 복사해 새로운 메모리에 할당하는 과정이 있기 때문에 capacity를 미리 예약해두는 것이 좋음  
  이 과정에서 기존 데이터의 소멸자가 호출되어 비효율적인 과정이 발생함 (생성자는 호출 X) 
  
  * **vector와 List의 차이**
    * vector는 메모리가 연속적으로 할당되어 있기 때문에 index 접근이 가능하고 메모리 접근이 빠름
    * List는 메모리가 연속적으로 할당되어 있지 않기 때문에 index 접근이 불가능하고 메모리 접근이 느림
    * 또한 vector는 메모리가 연속적인 배열이기 때문에 캐시 히트가 발생할 확률이 높음  
      list는 메모리가 연속적이지 않기 때문에 캐시 히트가 발생할 확률이 낮음  
      (단 element의 크기가 큰 경우 둘 다 캐시 히트가 발생할 확률이 낮음)  
    * List는 자료의 순서가 중요한 경우 사용하는 것이 좋고  
      Vector는 자료의 순서가 중요하지 않은 경우 사용하는 것이 좋음  
      순서가 중요한 자료인 경우 vector는 중간에 자료를 삽입하거나 삭제할 때  
      뒤의 자료들을 한칸씩 뒤로 밀어야 하기 때문에 비효율적임  
      List는 순서가 중요한 자료를 중간에 삽입하거나 삭제하더라도 O(1)이기 때문에 효율적임  
      이러한 이유로 List에는 Vector에는 없는 sort가 있음 (외부 라이브러리 사용 시 STL내장보다 느림)

    * ```cpp
        #include <iostream>
        #include <list>
        #include <vector> // 배열(재할당되는 배열)
        #include <array>  // 배열(크기가 고정)
        #include <algorithm>
        class TUser
        {
        public:
            int  m_id = 0;
            char m_szName[30] = { 0, };

            TUser(const TUser& d)			   // 복사 생성자
            {
                m_id = d.m_id;
                std::cout << "User(TUser& d)" << m_id << "\n";
            }
            TUser(TUser&& data)                 // 이동 생성자       
            {
                m_id = data.m_id;
                std::cout << "TUser(TUser&& data)" << m_id << "\n";
            }
            TUser& operator = (TUser& data)     // 복사 대입 연산자
            {
                m_id = data.m_id;
                std::cout << "operator =" << m_id << "\n";
                return *this;
            }
            TUser& operator = (TUser&& data)    // 이동 대입 연산자
            {
                m_id = data.m_id;
                std::cout << "operator = (TUser&& data" << m_id << "\n";
                return *this;
            }

            TUser(int id, const char* name, int iSize) : m_id(id)
            {
                memset(m_szName, 0, sizeof(char) * 30);
                int iLen = strlen(name);                //strlen() : size 없이도 가능
                memcpy(m_szName, name, strlen(name));
                std::cout << "TUser" << m_id << "\n";
            }
            TUser(int id) : m_id(id)
            {
                memset(m_szName, 0, sizeof(char) * 30);
                std::cout << "TUser" << m_id << "\n";
            }

            // 바로 포인터로 전달 시 호출
            //TUser(TUser* pUser)
            //{
            //    TUser(std::move(*pUser));
            //}

            TUser() = default; // = default; = TUser() = { } // = delete; 기본 생성자 삭제
            ~TUser()
            {
                std::cout << "~TUser" << m_id << "\n";
            }
            static void Print(TUser& user)
            {
                std::cout << user.m_szName << "\n";
            }


        };

        TUser AddTUser()
        {
            TUser user;
            return user;
        } // create rvalue TUser 

        int main()
        {
            std::vector<TUser> list;

            list.reserve(100); // 메모리 공간 예약
            //list.resize(100);  // 메모리 공간 할당

            for (int i = 0; i < 100; i++) //if i > 100 : 메모리 재할당이 일어나 기존 메모리를 복사해 새로운 메모리에 할당 
            {                             //이 과정에서 기존 메모리의 데이터의 소멸자가 호출되어 메모리 복사와 소멸자 호출이라는 비효율적 과정 발생
                

                // push_back() : vector의 끝에 객체를 추가
                // 전달한 객체를 복사하거나 이동시켜 값을 저장 (따로 추가 연산 필요)
                list.push_back(TUser(i)); //이동 생성자 호출
                list.push_back(AddTUser()); //이동 생성자 호출
                
                TUser* user1 = new TUser();
                list.push_back(*user1); //복사 생성자 호출
                
                TUser user2(i);
                list.push_back(user2);  //복사 생성자 호출



                // emplace_back() : vector의 끝에 객체를 추가
                list.emplace_back(i); // 필요한 인자를 직접 전달하여 인자에 맞는 생성자로 저장 (추가 연산 필요 없음)
                list.emplace_back(i,"name",0);
                list.emplace_back(TUser(i)); // 이동 생성자 호출
                list.emplace_back(AddTUser()); // 이동 생성자 호출

                TUser d;
                list.emplace_back(d); // 복사 생성자 호출

                TUser* pd = new TUser(i);
                list.emplace_back(*pd); // 복사 생성자 호출

                //TUser* d = new TUser(i);
                //list.emplace_back(d); // 포인터가 인자인 생성자 호출
            }

            std::sort(list.begin(), list.end(), [](TUser& d1, TUser& d2) { return d1.m_id < d2.m_id; }); // 람다식을 이용한 정렬

            //for (auto value : list) // &가 없으면 복사 생성
            for (auto& value : list)  // auto& : 복사가 아닌 참조로 받아옴 
            {
                value.m_id; // 복사된 객체의 id값을 출력
            }

            list.clear();               // vector의 size를 0으로 만들고 내부 원소의 소멸자 호출, 하지만 vector의 capacity는 그대로 유지

        ```
    </br></br>

* ## Map
  * 검색에 최적화된 자료구조로 BST를 사용해 구현되어 있음
  * 자료의 순서가 중요하지 않고(push back을 해도 순서대로 저장이 안됨)
  * 자료의 키와 값이 쌍(pair)으로 저장되어 있음
  * 
</br></br>

* ## UnOrdered_Map
  * hash table을 사용해 구현되어 있는 Map
</br></br>

* ## Hash
  * Hash Table : 키를 값에 대응시키는 구조인 Hash Map을 구현한 자료구조


