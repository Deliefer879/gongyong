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
                new Profile(){ Name = "b", Height = 2 },
                new Profile(){ Name = "c", Height = 3 },
                new Profile(){ Name = "d", Height = 4 },
                new Profile(){ Name = "e", Height = 5 },
            };

            var profiles = arrProfile.
                               Where(profile => profile.Height < 3).
                               OrderBy(profiles => profiles.Height).
                               Select(profiles =>
                                   new
                                   {
                                       Name = profiles.Name,
                                       InchHeight = profiles.Height * 0.393
                                   });

            foreach (var profile in profiles)
                Console.WriteLine($"{profile.Name}, {profile.InchHeight}");
        }
    }
}
