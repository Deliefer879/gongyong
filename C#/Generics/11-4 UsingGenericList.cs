using System;
using System.Collections.Generic;

namespace C____.Generics
{
    class MainApp
    {
        static void Main(string[] args)
        {
            List<int> list = new List<int>();
            for (int i = 0; i < 5; i++)
                list.Add(i);

            foreach (int element in list)
                Console.Write($"{element}");
            Console.WriteLine();

            list.Remove(2);

            foreach (int element in list)
                Console.Write($"{element}");
            Console.WriteLine();

            list.Insert(2, 2);

            foreach (int element in list)
                Console.Write($"{element}");
            Console.WriteLine();

        }
    }
}
