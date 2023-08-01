using System;
using System.Linq;

namespace C____.LINQ
{
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
                new Profile(){ Name = "a", Height = 1 },
                new Profile(){ Name = "b", Height = 3 },
                new Profile(){ Name = "c", Height = 5 },
                new Profile(){ Name = "d", Height = 7 },
                new Profile(){ Name = "e", Height = 9 },
            };

            var heightStat = from profile in arrProfile
                             group profile by profile.Height < 6 into g
                             select new
                             {
                                 Group = g.Key == true ? "under 6" : "over 6",
                                 Count = g.Count(),
                                 Max = g.Max(profile => profile.Height),
                                 Min = g.Min(profile => profile.Height),
                                 Average = g.Average(profile => profile.Height)
                             };

            foreach (var stat in heightStat)
            {
                Console.WriteLine("{0} - Count : {1}, Max : {2} ",stat.Group, stat.Count,stat.Max);
                Console.WriteLine("Min : {0}, Average : {1} ",stat.Min,stat.Average);
            }

        }
    }
}
