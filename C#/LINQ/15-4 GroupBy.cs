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
}
