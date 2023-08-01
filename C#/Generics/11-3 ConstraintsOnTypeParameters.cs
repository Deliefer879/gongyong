using System;

namespace C____.Generics
{
    //값 형식
    class StructArray<T> where T : struct
    {
        public T[] Array { get; set; }
        public StructArray(int size)
        {
            Array = new T[size];
        }
    }

    //참조 형식
    class RefArray<T> where T : class
    {
        public T[] Array { get; set; }
        public RefArray(int size)
        {
            Array = new T[size];
        }
    }

    // 기반 클레스
    class Base { }
    class Derived : Base { }
    class BaseArray<U> where U : Base
    {
        public U[] Array { get; set; }
        public BaseArray(int size)
        {
            Array=new U[size];
        }

        public void CopyArray<T>(T[] Source) where T : U
        {
            Source.CopyTo(Array, 0);
        }
    }

    // 인터페이스 클레스
    interface IInterface { void func(); }
    class BaseClass_Interface : IInterface { public void func() { } }
    class InterfaceArray<U> where U : IInterface
    {
        public U[] Array { get; set; }
        public InterfaceArray(int size)
        {
            Array = new U[size];
        }

        public void CopyArray<T>(T[] Source) where T : U
        {
            Source.CopyTo(Array, 0);
        }
    }


    class MainApp
    {
        public static T CreateInstance<T>() where T : new()
        {
            return new T();
        }

        static void Main(string[] args)
        {
            StructArray<int> a = new StructArray<int>(3);
            a.Array[0] = 0;
            a.Array[1] = 1;
            a.Array[2] = 2;

            RefArray<StructArray<double>> b = new RefArray<StructArray<double>>(3);
            b.Array[0] =  new StructArray<double>(5);
            b.Array[1] =  new StructArray<double>(10);
            b.Array[2] =  new StructArray<double>(1005);

            BaseArray<Base> c = new BaseArray<Base>(3);
            c.Array[0] = new Base();
            c.Array[1] = new Derived();
            c.Array[2] = CreateInstance<Base>();

            BaseArray<Derived> d = new BaseArray<Derived>(3);
            d.Array[0] = new Derived(); //Base형식은 여기에 할당 불가능
            d.Array[1] = CreateInstance<Derived>();
            d.Array[2] = CreateInstance<Derived>();

            BaseArray<Derived> e = new BaseArray<Derived>(3);
            e.CopyArray<Derived>(d.Array);

            //InterfaceArray<Base> f = new InterfaceArray<Base>(3);
            InterfaceArray<BaseClass_Interface> f = new InterfaceArray<BaseClass_Interface>(3);
            f.Array[0] = new BaseClass_Interface();
            f.Array[1] = CreateInstance<BaseClass_Interface>();
            f.Array[2] = CreateInstance<BaseClass_Interface>();

        }
    }

}
