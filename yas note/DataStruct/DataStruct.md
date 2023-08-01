DataStruct
==========

### [MSDN](https://docs.microsoft.com/ko-kr/dotnet/api/system.collections.generic?view=net-6.0) 

C#에 네임스페이스인 System.Collections을 사용하면 stack과 같은 자료구조를 바로 사용할수있다.

***
## 기본적인 자료구조들
   1. Dictionary
   2. List
   3. Queue
   4. Stack


아래의 클래스, 인터페이스는 System.Collections.Generic의 것으로 일반화가 가능하다

### 1.Dictionary
> 클래스
> > Dictionary<TKey,TValue>  

> 인터페이스 
> > IDictionary<TKey,TValue>
> > IReadOnlyDictionary<TKey,TValue>

### 2.List
> 클래스  
> > List<>  
> > LinkedList<>

> 인터페이스  
> > IList<>
> > IReadOnlyList<>

### 3.Queue
> 클래스  
> > Queue<>
> > PriorityQueue<TElement, TPriority>

### 4.Stack
> 클래스  
> > Stack<>

### 5.추가적인 인터페이스
> IEnumerable<> : 지정된 형식의 컬렉션을 반복할수 있도록 지원하는 열거자를 노출  
> IEnumerator<> : 제네릭 컬렉션을 단순하게 반복할 수 있도록 지원  
> * 위의 인터페이스는 System.Collections.Generic의 클래스에는 포함되어 있음
> * 만약 사용자가 임의로 클래스 생성시키더라고 위의 인터페이스를 추가하면 LINQ 사용이 가능해짐