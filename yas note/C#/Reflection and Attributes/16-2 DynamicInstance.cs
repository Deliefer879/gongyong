using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Reflection;

namespace C____.Reflection_and_Attributes
{
    class Profile
    {
        private string name;
        private string phone;

        public Profile()
        {
            name = ""; phone = "";
        }

        public Profile(string name, string phone)
        {
            this.name = name;
            this.phone = phone;
        }

        public void Print()
        {
            Console.WriteLine($"{name}, {phone}");
        }

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public string Phone
        {
            get { return phone; }
            set { phone = value; }
        }
    }

    class MainApp
    {
        static void Main(string[] args)
        {
            Type type = Type.GetType("C____.Reflection_and_Attributes.Profile");
            MethodInfo methodInfo = type.GetMethod("Print");
     
            PropertyInfo nameProperty = type.GetProperty("Name");
            PropertyInfo phoneProperty = type.GetProperty("Phone");

            object profile = Activator.CreateInstance(type, "abc", "111-2222");
            methodInfo.Invoke(profile, null);

            profile = Activator.CreateInstance(type);
            nameProperty.SetValue(profile, "bbb", null);
            phoneProperty.SetValue(profile, "333-4444", null);

            Console.WriteLine("{0}, {1}",nameProperty.GetValue(profile, null), phoneProperty.GetValue(profile,null));
        }
    }
}
