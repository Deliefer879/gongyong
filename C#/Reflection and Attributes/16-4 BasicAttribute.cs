using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C____.Reflection_and_Attributes
{
    class MyClass
    {
        [Obsolete("OldMethod는 폐기되었습니다. NewMethod()를 이용하세요.")]
        public void OldMethod()
        {
            Console.WriteLine("I'm old");
        }

        public void NewMethod()
        {
            Console.WriteLine("I'm new");
        }
    }

    class MainApp
    {
        static void Main(string[] args)
        {
            MyClass obj = new MyClass();
            obj.OldMethod();
            obj.NewMethod();
        }
    }

}
