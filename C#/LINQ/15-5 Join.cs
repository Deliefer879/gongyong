using System;
using System.Linq;

namespace C____.LINQ
{
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
}
