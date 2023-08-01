using System;
using System.Collections.Generic;
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

            var profiles = from profile in arrProfile
                           where profile.Height < 3
                           orderby profile.Height
                           select new
                           {
                               Name = profile.Name,
                               InchHeight = profile.Height * 0.393
                           };

            foreach (var profile in profiles)
                Console.WriteLine($"{profile.Name}, {profile.InchHeight}");

        }
    }
}
