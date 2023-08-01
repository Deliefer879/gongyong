LINQ
====

### [MSDN](https://docs.microsoft.com/ko-kr/dotnet/csharp/programming-guide/concepts/linq/introduction-to-linq-queries) 


 데이터 질의 기능으로  
 C#에서 SQL과 유사한 방법으로 데이터 가공이 가능해짐  
 
 ## 1) LINQ의 기본
  1. from    : 어떤 데이터에서 찾을 것인가?
  2. where   : 어떤 조건으로 찾을 것인가?
  3. orderby : 어떤 항목을 기준으로 정렬할 것인가?
  4. select  : 어떤 항목을 추출할 것인가?

```C#    
class MainApp
{
    class Class
    {
        public string Name { get; set; }
        public int[] Score { get; set; }
    }

    class MainApp
    {
        static void Main(string[] args)
        {
            Class[] arrClass =
            {
                new Class { Name = "green", Score = new int[] { 99,88,77,66 } },
                new Class { Name = "blue", Score = new int[] { 88,77,66,55 } },
                new Class { Name = "red", Score = new int[] { 77,66,55,44 } },
                new Class { Name = "yellow", Score = new int[] { 66,55,44,33 } }
            };

            var classes = from c in arrClass
                          from s in c.Score
                          where s < 60
                          orderby s
                          select new { c.Name, Low = s }; //읽기 전용인 Anonymous Type으로 반환 

            foreach (var c in classes)
                Console.WriteLine($"under 60 : {c.Name} ({c.Low})");

            foreach (var c in classes)
            {
                Console.WriteLine($"Type of classes : {classes.GetType()}");
                Console.WriteLine($"Type of c : {c.GetType()}");
            }
        }
    }
 }
```
* from의 데이터 원본은 IEnumerable<> 인터페이스를 상속해야하며
* from을 중첩하여 여러개의 데이터에 접근이 가능하며 위의 코드에서는 arrClass에서 얻은 c에 한번 더 from을 사용하였다.
* result의 데이터의 타입은 select로 추출한 n의 타입과 같다
* select문은 익명 형식을 사용할수도 있으며 이때 반환타입은 AnonymousType이다.

***

## 2) group by와 join을 사용한 데이터 분류 및 병합

### 1. group by : 데이터 분류

```C#
    class Profile
    {
        public string Name { get; set; }
        public int Height { get; set; }
    }

    class MainApp
    {
        static void Main(string[] args)
        {
            Profile[] arrProfile =
            {
                new Profile() { Name = "a", Height=1},
                new Profile() { Name = "b", Height=3},
                new Profile() { Name = "c", Height=5},
                new Profile() { Name = "d", Height=3},
                new Profile() { Name = "e", Height=2},
            };

            var listProfile = from profile in arrProfile
                              orderby profile.Height
                              group profile by profile.Height < 3 into g        // profile.Height < 3 의 결과를 바탕으로 group을 분리
                              select new { GroupKey = g.Key, Profiles = g };    // g.key는 bool 값을 return

            foreach(var Group in listProfile)
            {
                Console.WriteLine($" under 3 : {Group.GroupKey}");

                foreach (var profile in Group.Profiles)
                    Console.WriteLine($" >>> {profile.Name}, {profile.Height}");
            }
        }
    }
```
* g.Key는 bool값을 가지고 있으며 조건을 만족하면 true 아니면 false를 가지고 있다.
* group by를 사용하여 group을 나누더라도 원본 데이터에서 손실되는 데이터는 없다.

### 2. join : 데이터 병합

```C#
    class Profile
    {
        public string Name { get; set; }
        public int Height { get; set; }
    }

    class Product
    {
        public string Title { get; set; }
        public string Star { get; set; }
    }

    class MainApp
    {
        static void Main(string[] args)
        {

            Profile[] arrProfile =
            {
                new Profile() { Name = "a", Height=1},
                new Profile() { Name = "b", Height=3},
                new Profile() { Name = "c", Height=5},
                new Profile() { Name = "d", Height=3},
                new Profile() { Name = "e", Height=2},
            };
            Product[] arrProduct =
            {
                new Product() { Title = "a title", Star = "a"},
                new Product() { Title = "b title", Star = "b"},
                new Product() { Title = "d title", Star = "d"},
                new Product() { Title = "e title", Star = "e"},
                new Product() { Title = "f title", Star = "f"},
            };

            var listProfile = 
                from profile in arrProfile
                join product in arrProduct on profile.Name equals product.Star //equals 대신 == 사용불가능
                select new 
                {
                    Name = profile.Name,
                    Work = product.Title,
                    Height = profile.Height
                };
            
            Console.WriteLine("---- 내부 조인 결과 ----");    //원본 데이터들 중 1개라도 비어 있다면 join결과에서 제외됨
            foreach(var profile in listProfile)
            {
                Console.WriteLine("name : {0}, title : {1}, heigth : {2}",profile.Name,profile.Work,profile.Height);
            }

            listProfile = 
                from profile in arrProfile
                join product in arrProduct on profile.Name equals product.Star into ps
                from product in ps.DefaultIfEmpty(new Product(){Title = "nothing"})
                select new 
                {
                    Name = profile.Name,
                    Work = product.Title,
                    Height = profile.Height
                };

            Console.WriteLine();
            Console.WriteLine("---- 외부 조인 결과 ----");    //원본 데이터들의 모든 데이터가 join결과에 포함
            foreach (var profile in listProfile)
            {
                Console.WriteLine("name : {0}, title : {1}, heigth : {2}",profile.Name,profile.Work,profile.Height);
            }
        }
    }
```

* join은 내부와 외부 2가지로 나눌수 있다.
* 내부 조인은 데이터 병합시 다른 한쪽에 데이터가 존재하지 않는다면 결과에서 제외되며
* 외부 조인은 데이터가 없더라도 결과에 포함된다.

***

# LINQ 표준 쿼리 연산자
표준 쿼리 연산자는 LINQ패턴을 형성하는 메서드로   
IEnumerable<>, IQueryable<>을 구현하는 개체 대부분에서 작동

> 정렬
> 1. OrderBy : 오름차순으로 정렬
> 2. ThenBy : 오름차순 2차 정렬

> 집합
> 1. Distinct : 중복값을 제거
> 2. Intersect : 두 컬렉션 사이의 교집합을 반환

> 필터링
> 1. Where : 필터링 조건을 만족하는 값 추출

> 수량 연산
> 1. All : 모든 요소가 임의의 조건을 모두 만족시키는지 평가 (return bool)
> 2. Any : 하나의 요소라도 조건을 만족시키는지 평가(return bool)

> 데이터 분할
> 1. TakeWhile : 입력된 조건 함수를 만족시키는 요소들을 취합

> 요소 접근
> 1. ElementAtOrDefault : 임의의 인덱스에 존재하는 요소를 반환하되 범위를 벗어날 때 기본값 반환
> 2. FirstOrDefault : 조건식을 만족하는 첫 번째 요소를 반환하되 값이 없을시 기본값을 반환
> 3. LastOrDefault :  조건식을 만족하는 마지막 요소를 반환하되 값이 없을시 기본값을 반환
> 4. SingleOrDefault : 조건식을 만족하는 유일한 요소를 반환하되 값이 없을시 기본값을 반환

> 형식 변환  
> 1. Cast : 컬렉션의 요소들을 특정 형식으로 변환합니다.