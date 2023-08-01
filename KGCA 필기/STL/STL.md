# STL

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
  * �˻��� ����ȭ�� �ڷᱸ���� BST�� ����� �����Ǿ� ����
  * �ڷ��� ������ �߿����� �ʰ�(push back�� �ص� ������� ������ �ȵ�)
  * �ڷ��� Ű�� ���� ��(pair)���� ����Ǿ� ����
  * 
</br></br>

* ## UnOrdered_Map
  * hash table�� ����� �����Ǿ� �ִ� Map
</br></br>

* ## Hash
  * Hash Table : Ű�� ���� ������Ű�� ������ Hash Map�� ������ �ڷᱸ��


