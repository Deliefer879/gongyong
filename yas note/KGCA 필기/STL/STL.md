# STL
ZeroMemory() : �޸𸮸� 0���� �ʱ�ȭ  
STL �����̳ʰ� ���Ե� ��ü �ʱ�ȭ �� ����� ����ϸ� �ȵ�(iter��  �ʱ�ȭ!)

* ## vector
  * Queue�� ���� �迭 ������ ������ ����
  * array�� �޸� �ڷ���� ���� ũ�Ⱑ �ڵ����� �þ
  * �ڷ��� ����, ������ ����ϰ� �Ͼ�� ��� List�� ����ϴ� ���� ����
  * �迭�̱� ������ emplace���� ����� ���̳� �߰��� �ڷ� ���� �� ���� �ڷ���� ��ĭ�� �ڷ� �о�� �ϱ� ������ ��ȿ����
  * List�� �޸� �޸𸮰� ���������� �Ҵ�Ǿ� �ֱ� ������ �޸� ������ ������ index ������ ������(List�� �Ұ���)
  * �޸� �Ҵ��� �Ͼ �� ���� �޸��� �����͸� ������ ���ο� �޸𸮿� �Ҵ��ϴ� ������ �ֱ� ������ capacity�� �̸� �����صδ� ���� ����  
  �� �������� ���� �������� �Ҹ��ڰ� ȣ��Ǿ� ��ȿ������ ������ �߻��� (�����ڴ� ȣ�� X) 
  
  * **vector�� List�� ����**
    * vector�� �޸𸮰� ���������� �Ҵ�Ǿ� �ֱ� ������ index ������ �����ϰ� �޸� ������ ����
    * List�� �޸𸮰� ���������� �Ҵ�Ǿ� ���� �ʱ� ������ index ������ �Ұ����ϰ� �޸� ������ ����
    * ���� vector�� �޸𸮰� �������� �迭�̱� ������ ĳ�� ��Ʈ�� �߻��� Ȯ���� ����  
      list�� �޸𸮰� ���������� �ʱ� ������ ĳ�� ��Ʈ�� �߻��� Ȯ���� ����  
      (�� element�� ũ�Ⱑ ū ��� �� �� ĳ�� ��Ʈ�� �߻��� Ȯ���� ����)  
    * List�� �ڷ��� ������ �߿��� ��� ����ϴ� ���� ����  
      Vector�� �ڷ��� ������ �߿����� ���� ��� ����ϴ� ���� ����  
      ������ �߿��� �ڷ��� ��� vector�� �߰��� �ڷḦ �����ϰų� ������ ��  
      ���� �ڷ���� ��ĭ�� �ڷ� �о�� �ϱ� ������ ��ȿ������  
      List�� ������ �߿��� �ڷḦ �߰��� �����ϰų� �����ϴ��� O(1)�̱� ������ ȿ������  
      �̷��� ������ List���� Vector���� ���� sort�� ���� (�ܺ� ���̺귯�� ��� �� STL���庸�� ����)

    * ```cpp
        #include <iostream>
        #include <list>
        #include <vector> // �迭(���Ҵ�Ǵ� �迭)
        #include <array>  // �迭(ũ�Ⱑ ����)
        #include <algorithm>
        class TUser
        {
        public:
            int  m_id = 0;
            char m_szName[30] = { 0, };

            TUser(const TUser& d)			   // ���� ������
            {
                m_id = d.m_id;
                std::cout << "User(TUser& d)" << m_id << "\n";
            }
            TUser(TUser&& data)                 // �̵� ������       
            {
                m_id = data.m_id;
                std::cout << "TUser(TUser&& data)" << m_id << "\n";
            }
            TUser& operator = (TUser& data)     // ���� ���� ������
            {
                m_id = data.m_id;
                std::cout << "operator =" << m_id << "\n";
                return *this;
            }
            TUser& operator = (TUser&& data)    // �̵� ���� ������
            {
                m_id = data.m_id;
                std::cout << "operator = (TUser&& data" << m_id << "\n";
                return *this;
            }

            TUser(int id, const char* name, int iSize) : m_id(id)
            {
                memset(m_szName, 0, sizeof(char) * 30);
                int iLen = strlen(name);                //strlen() : size ���̵� ����
                memcpy(m_szName, name, strlen(name));
                std::cout << "TUser" << m_id << "\n";
            }
            TUser(int id) : m_id(id)
            {
                memset(m_szName, 0, sizeof(char) * 30);
                std::cout << "TUser" << m_id << "\n";
            }

            // �ٷ� �����ͷ� ���� �� ȣ��
            //TUser(TUser* pUser)
            //{
            //    TUser(std::move(*pUser));
            //}

            TUser() = default; // = default; = TUser() = { } // = delete; �⺻ ������ ����
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

            list.reserve(100); // �޸� ���� ����
            //list.resize(100);  // �޸� ���� �Ҵ�

            for (int i = 0; i < 100; i++) //if i > 100 : �޸� ���Ҵ��� �Ͼ ���� �޸𸮸� ������ ���ο� �޸𸮿� �Ҵ� 
            {                             //�� �������� ���� �޸��� �������� �Ҹ��ڰ� ȣ��Ǿ� �޸� ����� �Ҹ��� ȣ���̶�� ��ȿ���� ���� �߻�
                

                // push_back() : vector�� ���� ��ü�� �߰�
                // ������ ��ü�� �����ϰų� �̵����� ���� ���� (���� �߰� ���� �ʿ�)
                list.push_back(TUser(i)); //�̵� ������ ȣ��
                list.push_back(AddTUser()); //�̵� ������ ȣ��
                
                TUser* user1 = new TUser();
                list.push_back(*user1); //���� ������ ȣ��
                
                TUser user2(i);
                list.push_back(user2);  //���� ������ ȣ��



                // emplace_back() : vector�� ���� ��ü�� �߰�
                list.emplace_back(i); // �ʿ��� ���ڸ� ���� �����Ͽ� ���ڿ� �´� �����ڷ� ���� (�߰� ���� �ʿ� ����)
                list.emplace_back(i,"name",0);
                list.emplace_back(TUser(i)); // �̵� ������ ȣ��
                list.emplace_back(AddTUser()); // �̵� ������ ȣ��

                TUser d;
                list.emplace_back(d); // ���� ������ ȣ��

                TUser* pd = new TUser(i);
                list.emplace_back(*pd); // ���� ������ ȣ��

                //TUser* d = new TUser(i);
                //list.emplace_back(d); // �����Ͱ� ������ ������ ȣ��
            }

            std::sort(list.begin(), list.end(), [](TUser& d1, TUser& d2) { return d1.m_id < d2.m_id; }); // ���ٽ��� �̿��� ����

            //for (auto value : list) // &�� ������ ���� ����
            for (auto& value : list)  // auto& : ���簡 �ƴ� ������ �޾ƿ� 
            {
                value.m_id; // ����� ��ü�� id���� ���
            }

            list.clear();               // vector�� size�� 0���� ����� ���� ������ �Ҹ��� ȣ��, ������ vector�� capacity�� �״�� ����

        ```
    </br></br>

* ## Map
  * ### Common
    * �ڷ��� ������ �߿����� �ʰ�(push back�� �ص� ������� ������ �ȵ�)
    * �ڷ��� Ű�� ���� ��(pair)���� ����Ǿ� ����
  * ### Map
    * �˻��� ����ȭ�� �ڷᱸ���� BST�� ����� �����Ǿ� ����
  * ### UnOrdered_Map
    * hash table�� ����� �����Ǿ� �ִ� Map

```cpp

    // map has same function with unordered_map
    // so you can change map to unordered_map
    using MyMap = std::map<int, std::string>;

    MyMap mapList1;
    std::pair<int, std::string> pairdata;

    pairdata.first = 10;
    pairdata.second = "value 10";
    mapList1.insert(pairdata);

    mapList1[20] = "value 20";      // this is not good way
    mapList1[20] = "value 20_2";    // it will be changed

    mapList1.insert(std::make_pair(23, "��3��"));
    mapList1.insert(std::make_pair(23, "��5��")); // it will not be changed

    MyMap::iterator d1 = mapList1.find(9); // find return iterator
    
    // loop use copy value
    for (std::pair<int, std::string> d2 : mapList1) 
    {
        int key = d2.first;
        std::string value = d2.second;
    }

    // loop use ref value
    for (auto& d7 : mapList1)
    {
        int key = d7.first;
        std::string value = d7.second;
    }

    // loop use iterator
    for (MyMap::iterator d3 = mapList1.begin(); d3 != mapList1.end(); d3++)
    {
        int key = d3->first;
        std::string value = d3->second;
    }

    // index access
    for (int iKey = 0; iKey < mapList1.size(); iKey++)
    {
        std::cout << mapList1[iKey].c_str();
    }
    


```
</br></br>

* ## Pair, Tuple
  * ### Pair
    * �� ���� �ڷḦ �ϳ��� ������ ���� �����ϴ� �ڷᱸ��
    * pair ��ü�� ���� ���� make_pair() �Լ��� ���
    * pair ��ü�� ��� ���� first, second�� ����Ͽ� ����
  * ### Tuple
    * ���� ���� �ڷḦ �ϳ��� ������ ���� �����ϴ� �ڷᱸ��
</br></br>

* ## Priority Queue
  * �ڷḦ ������ ������ �ƴ϶� �켱������ ���� �ڷᰡ ��ġ�Ǵ� �ڷᱸ��
  * �켱���� ť�� Heap�� �����ϴ� ���� �Ϲ���