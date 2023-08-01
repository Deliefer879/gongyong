using System;
using System.Linq;
using System.Reflection;

namespace C____.LINQ
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
                          select new { c.Name, Low = s };   //Low라는 새로운 필드를 생성하며    
                                                            //읽기 전용인 Anonymous Type으로 반환 

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
