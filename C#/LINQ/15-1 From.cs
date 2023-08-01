using System;
using System.Collections.Generic;
using System.Linq;

//LINQ의 대상은 IEnumerable<T> 인터페이스를 상속해야 함.

namespace C____.LINQ
{
    class MainApp
    {
        static void Main(string[] args)
        {
            int[] numbers = { 9, 2, 6, 4, 5, 3, 7, 8, 1, 10 };

            var result = from n in numbers
                         where n % 2 == 0
                         orderby n
                         select n;

            foreach(int n in result)
                Console.WriteLine($"짝수 : {n}");

        }
    
    }
}
